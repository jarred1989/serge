/*************************************************************//**
*
*	@file	vae_util.h
*	@date	02/01/2019
*	@author Martin Fouilleul
*
*****************************************************************/
#ifndef __VAE_UTIL_H_
#define __VAE_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------
// vae_model wrapper
//-----------------------------------------------------------------

#define VAE_MODEL_OK		0
#define VAE_MODEL_NOT_LOADED	-1
#define VAE_MODEL_BAD_SIZE	-2
#define VAE_MODEL_THROW		-3


typedef struct vae_model_t vae_model;

vae_model* VaeModelCreate();
void VaeModelDestroy(vae_model* model);
int  VaeModelLoad(vae_model* model, const char* path);
int VaeModelHasCuda(vae_model* model);
int VaeModelGetSpectrogram(vae_model* model, unsigned int count, float* buffer, float c0, float c1, float c2, float c3, int note);

#ifdef __cplusplus
} // extern "C"
#endif


#endif //__VAE_UTIL_H_
