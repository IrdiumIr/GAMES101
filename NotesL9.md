# GAMES101-Lecture9
## Shading 3 (Texture Mapping)
>### References
>* Chapter11 Texture Mapping(11.1, 11.2)
***

## Main Topics
* Texture Mapping
* Barycentric coordinates
* Texture queries
* Applications of textures
* Shadow mapping

## Texture Mapping

* ### Understanding
  * 3D物体的表面都是2D的 : 纹理就是一张图
    * 纹理映射：把这张图蒙在一个3D物体上
    * 物体映射到纹理坐标系 : $[0,1]^2$
    * 纹理的可复用性

## Barycentric coordinates(Interpolation)

* ### Reason for interpolation
  * Specify values at **vertices**
  * Obtain smoothly varying values **across triangles**
  * Interpolate : texture coordinates, colors, normal vectors, ...

* ### Barycentric coordinates
  * Program vertex and fragment processing stages
  * 自己编程顶点和像素的着色流程,每个元素都执行一次 (no need "for loop)
  * More :
    * Geometry Shader
    * Compute Shader
  * [ShaderToy](https://www.shadertoy.com/)