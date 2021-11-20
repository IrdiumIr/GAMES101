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
  * Compose any 3D rotation from $\mathbf{R}_x,\mathbf{R}_y,\mathbf{R}_z$
  * ***Euler Angles***

* ### Rodrigues' Rotation Fomula
  * $\mathbf{R}(\mathbf{n},\alpha)=\cdots=\cos(\alpha)\mathbf{I}+(1-\cos(\alpha))\mathbf{n}\mathbf{n}^T+\sin(\alpha)\begin{pmatrix}0&-n_z&n_y\\n_z&0&-n_x\\-n_y&n_x&0\end{pmatrix}$
    * $\mathbf{n}$ 默认过 $O(0,0,0)$
    * $(\mathbf{v}\cdot\mathbf{k})\mathbf{k}=\mathbf{k}(\mathbf{v}\cdot\mathbf{k})=\mathbf{k}(\mathbf{k}^T\cdot\mathbf{v})$
