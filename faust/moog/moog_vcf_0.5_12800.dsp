// Author: Thibault Geoffroy
import("stdfaust.lib");
res = 0.5;
freq = 12800;
process = ve.moog_vcf_2bn(res, freq);
