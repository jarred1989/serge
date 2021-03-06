#author: Antoine CAILLON
import numpy as np
import librosa as li
import matplotlib.pyplot as plt
from os import system

system("mkdir motu_dataset")

x,fs = li.load("session.wav", sr=22050)
n    = 13*2*4
s    = abs(x/max(abs(x)))
s[s<.1] = 0

peaks = li.util.peak_pick(s, 1000, 1000, 1000, 1000, 0, 15000)
print("%d peaks found over %d" % (len(peaks),n))

def pad(x,n):
    m = len(x)
    if m<n:
        return np.concatenate([x,np.zeros(n-m)])
    else:
        return x[:n]

maxv = np.iinfo(np.int16).max

N = len(peaks)-1

for i in range(N):
    if i%(N//10)==0:
        print("{:02d} done".format(int(i/N*100)), end="\r")
    signal = pad(x[peaks[i]:peaks[i+1]-fs//10],34560)
    n      = len(signal)
    y      = np.zeros(34560)
    y[3*fs//10:] = signal[:-3*fs//10]
    li.output.write_wav("motu_dataset/motu_sample_{:03d}.wav".format(i), y, sr=fs, norm=True)
