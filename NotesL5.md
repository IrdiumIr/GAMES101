# GAMES101-Lecture5
## Rasterization 1 (Triangles)
>### References
>* Chapter3 Raster Images(3.1, 3.2)
***

## Main Topics
* Finishing Viewing Transformations
  * Viewport transformation
* Rasterization
  * Different raster displays
  * Rasterizing a triangle
* Occlusions and Visibility

## Viewing Transformations Cont.

* ### fovY and aspect ratio
  * fovY : field-of-view (vertical)
    * the angle from camera to object(bottom and top)
  * Aspect ratio = width / height
  * $\tan\dfrac{fovY}{2}=\dfrac{t}{|n|}$
  * $AspectRatio = \dfrac{r}{t}$

![fovY.png](https://i.loli.net/2021/11/21/T5yBx8bnsVdMPHh.png)

* ### Canonical Cube to Screen
  * Screen : array of pixels
    * Resolution : size of array
    * raster display
  * Raster == screen in German
    * Rasterize : draw onto the screen
  * Pixel : short for ***picture element***
    * pixel is little aquare with uniform color
    * Color is mixture of $(red, green, blue)$
  * Screen space
    * Pixel indices form : $(x, y)$
      * Pixel indices are from $(0, 0)$ to $(width-1, height-1)$
      * Pixel is centered at $(x+0.5, y+0.5)$
      * Screen covers from $(0, 0)$ to $(width, height)$
    * Transform in $xy$ plane : $[-1, 1]^2$ to $[0, width]\times[0, height]$
    * Viewport transform matrix
      * $M_{viewport}=\begin{pmatrix}\frac{width}{2}&0&0&\frac{width}{2}\\0&\frac{height}{2}&0&\frac{height}{2}\\0&0&1&0\\0&0&0&1\end{pmatrix}$

![pixel.png](https://i.loli.net/2021/11/22/qATuFvyH7Betbjp.png)

## Rasterization

* ### Why Triangles
  * Most basic polygon
    * Break up other polygons
  * Unique properties
    * Guaranteed to be planar
    * Well-defined interior
    * Well-defined method for interpolating values at vertices over triangle (barycentric interpolation) ：**(可内部插值)**

* ### Sampling : Pixel & Triangle
  * Evaluate a func at a point ***(discretize : 离散)***
    * sample time (1D), area/direction (2D), volume (3D) etc
  * Define func **$inside(tri, x, y)$**
    * $inside(t, x, y)=\begin{cases}1,\ \ (x,y)\ \ in triangle\ \ t\\0,\ \ otherwise\end{cases}$
  
    ```cpp {.line-numbers}
      for (int x = 0; x != xmax; ++x)
        for (int y = 0; y != ymax; ++y)
          image[x][y] = inside(tri, x+0.5, y+0.5);
    ```

  * **3** Cross product to makesure inside/outside
  * Edge Cases
    * Ignored(here) or specially(API)
  * Using a bounding box
    * avoid checking all pixels on screen
  * Incremental Triangle Traversal
    * 类似扫描线, 计算左右边界
    * faster
    * thin and rotated triangles
* ### Aliasing (Jaggies)
  * 走样锯齿问题