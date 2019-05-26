
/*
	2019.05.24
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_ONYX_RENDER_MATERIAL_H

#define _CLASS_ONYX_RENDER_MATERIAL_H

#include "./Context.h"
#include "./Mesh.h"
#include "./Shader.h"

#include <cassert>
#include <stdexcept>
#include <vector>

namespace Onyx::Render
{
	class Material final
	{
	public:
		Context *const pContext;
		Mesh *const pMesh;
		Shader *const pShader;

	private:
		VkPipeline vkPipeline;

	public:
		Material(Context *pContext, Mesh *pMesh, Shader *pShader);
		Material(const Material &sSrc) = delete;
		~Material();
		
	public:
		Material &operator=(const Material &sSrc) = delete;
		
	public:
		inline VkPipeline vulkanPipeline() const;
	};

	inline VkPipeline Material::vulkanPipeline() const
	{
		return this->vkPipeline;
	}
}

#endif