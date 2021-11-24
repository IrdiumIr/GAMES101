# GAMES101-Lecture7
## Shading 1 (Illumination, Shading and Graphics Pipeline)
>### References
>* Chapter10 Surface Shading(10.1)
***

## Main Topics
* Shading
  * Illumination & Shading
  * Graphics Pipeline

## Shading

* ### Shading Definition
  * Applying a **material** to an object
    * 材质

* ### Blinn-Phong Reflectance Model
  * Perceptual Observations
    * Specular highlights (高光)
    * Diffuse reflection (漫反射)
    * Ambient lighting (环境光照)
  * Local Shading
    * consider some parameters :
      * viewer direction $v$
      * surface normal $n$
      * light direction $l$
      * oher surface parameters
    * No **shadows** will be generated
  * **Diffuse Reflection**
    * Light is scattered **uniformly** in **all** directions
    * Lambert’s $cos$ law
      * How much light (energy) is received ($\cos\theta=n\cdot l$)
      * Light falloff
      * $L_d=k_d(I/r^2)max(0,n\cdot l)$
        * $k_d$ : diffuse coefficient
    * Independent of your *view* direction
  * **Specular Term**
    * Intensity depends on view direction
      * $v$ near mirror reflection direction
    * **half vector** (半程向量) near normal $n$
      * $h=$ bisector $(v,l)=\dfrac{v+l}{|v+l|}$
      * $L_s=k_s(I/r^2)max(0,\cos\alpha)^p=k_s(I/r^2)max(0,n\cdot h)^p$
      * p : narrows the reflection lobe (加快指数衰减,减少高光部分)
  * **Ambient Term**
    * depend on nothing
    * add constant color to account for disregarded illumination
    * approximate or fake

[![oiTIjf.png](https://z3.ax1x.com/2021/11/24/oiTIjf.png)](https://imgtu.com/i/oiTIjf)
