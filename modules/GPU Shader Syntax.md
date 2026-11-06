# 💡New Idea: GLSL Decorators
- Shader language is similar to C, with the addition of decorators
- OpenGL's shader language in called `GLSL`, or graphics library shader library
  - Compare to HLSL, Microsoft's language for DirectX
- Decorators proceed the variable type declaration
- [decorator] [type] [variable name]
  - For example: `uniform mat4 worldMatrix;`
- Uniforms in classic OpenGL
  -  `uniform` - values that are constant across all triangles
  -  `attribute` - values that change per vertex
  -  `varying` - values that change per fragment

# 💡New Idea: GLSL variables
- `float` - a scalar
- `vec2` - a 2D Vector
- `vec3` - a 3D Vector
- `vec3` - a 4D Vector
- `mat3` - a 3x3 Matrix
- `mat4` - a 4x4 Matrix