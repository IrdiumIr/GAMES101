# GAMES101-Lecture8
## Shading 2 (Shading and Graphics Pipeline)
>### References
>* Chapter10 Surface Shading(10.2)
>* Chapter17 Using Graphics Hardware(17.1)
***

## Main Topics
* Shading Frequencies
* Graphics Pipeline
* Texture Mapping

## Shading Frequencies

* ### Definition
  * Applying shading to *where*
    * patch / vertex / pixel (面,顶点,像素)

* ### Flat shading (each triangle)
  * Triangle face is flat 
    * one normal vector
    * using 2edges cross products
  * Not good for smooth surfaces

* ### Gouraud shading (each vertex)
  * **Interpolate** colors from vertices across triangle
    * 每个顶点Shading,并对颜色值在中间插值
  * each vertex has a normal vector

* ### Phong shading (each pixel)
  *  Interpolate normal vectors across each triangle
     *  对法线值做插值,对每个点做Shading
  *  Compute full shading model at *each pixel*
  *  几何足够复杂的情况下，用简单的Shading方法也可以达到好的效果

* ### Per-Vertex / Pixel $n$
  * Per-Vertex
    * 相邻面的法线的(加权)平均
  * Per-Pixel
    * Barycentric interpolation (重心坐标)

## Graphics Pipeline (Real-Time Rendering)

* ### Definition
  * 从顶点到光栅化到着色的一系列过程
  * Vertex Processing $\Rightarrow$ Triangle Processing $\Rightarrow$ Rasterization $\Rightarrow$ Fragment Processing $\Rightarrow$ Framebuffer Operations
    * 输入空间中三维顶点-投影到屏幕空间-三角形化-光栅化-着色-输出图像

* ### Shader
  * Program vertex and fragment processing stages
  * 自己编程顶点和像素的着色流程,每个元素都执行一次 (no need "for loop)
  * More :
    * Geometry Shader
    * Compute Shader
  * [ShaderToy](https://www.shadertoy.com/)