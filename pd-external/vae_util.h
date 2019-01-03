//*****************************************************************
//
//	$file: vae_util.h $
//	$author: Martin Fouilleul $
//	$date: 02/01/2019 $
//	$revision: $
//	$note: (C) 2019 by Martin Fouilleul - all rights reserved $
//
//*****************************************************************
#ifndef __VAE_UTIL_H_
#define __VAE_UTIL_H_

//-----------------------------------------------------------------
// vae_model wrapper
//-----------------------------------------------------------------

typedef struct vae_model_t vae_model;

vae_model* VaeModelCreate();
void VaeModelDestroy(vae_model* model);
int  VaeModelLoad(vae_model* model, const char* path);
int VaeModelGetSamples(vae_model* model, unsigned int count, float* buffer, float c0, float c1, float c2, float c3, float nu);

#endif //__VAE_UTIL_H_