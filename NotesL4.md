# GAMES101-Lecture4
## Transformation Cont.
>### References
>* Chapter6 Transformation Matrices(6.2, 6.4, 6.5)
>* Chapter7 Viewing
***

## Main Topics
* 3D Transformations
* Viewing ***(观测)*** Transformaitons
  * View (视图) / Camera transformation
  * Projection (投影) transformation
    * Orthographic (正交) projection
    * Perspective (透视) projection

## 3D Transformations

* ### 3D Rotation(around x-, y-, or z axis)
  * $\mathbf{R}_x(\alpha)=\begin{pmatrix}1&0&0&0\\0&\cos\alpha&-\sin\alpha&0\\0&\sin\alpha&\cos\alpha&0\\0&0&0&1\end{pmatrix}$
  * $\mathbf{R}_y(\alpha)=\begin{pmatrix}\cos\alpha&0&\sin\alpha&0\\0&1&0&0\\-\sin\alpha&0&\cos\alpha&0\\0&0&0&1\end{pmatrix}$
  * $\mathbf{R}_z(\alpha)=\begin{pmatrix}\cos\alpha&-\sin\alpha&0&0\\\sin\alpha&\cos\alpha&0&0\\0&0&1&0\\0&0&0&1\end{pmatrix}$
  * $\mathbf{R}_y(\alpha)$ seems **different** because of $\vec{z}\times\vec{x}=\vec{y}$, which is CCW.

* ### 3D Rotations
  * Compose any 3D rotation from $\mathbf{R}_x,\mathbf{R}_y,\mathbf{R}_z$
  * ***Euler Angles***

* ### Rodrigues' Rotation Fomula
  * $\mathbf{R}(\mathbf{n},\alpha)=\cdots=\cos(\alpha)\mathbf{I}+(1-\cos(\alpha))\mathbf{n}\mathbf{n}^T+\sin(\alpha)\begin{pmatrix}0&-n_z&n_y\\n_z&0&-n_x\\-n_y&n_x&0\end{pmatrix}$
    * $\mathbf{n}$ 默认过 $O(0,0,0)$
    * $(\mathbf{v}\cdot\mathbf{k})\mathbf{k}=\mathbf{k}(\mathbf{v}\cdot\mathbf{k})=\mathbf{k}(\mathbf{k}^T\cdot\mathbf{v})$

![Rodrigues.png](https://i.loli.net/2021/11/18/YENoKLIbBMDehm4.png)

## Viewing Transformation

>Model-***View***-Projection Transformation -> MVP

### View / Camera transformation

* #### Define the camera first
  * Position $\vec{e}$
  * Look-at direction $\vec{g}$
  * Up direction $\vec{t}$ ***(perp. to look-at)***

* #### Key observation
  * camera always transforms to **the origin, up at Y, look-at -Z**
  * transform the objects along with the camera

* #### $M_{view}$ in math
  * translate $\vec{e}$ to origin $O$
  * rotate $\vec{g}$ to $-Z$
  * rotate $\vec{t}$ to $Y$
  * rotate $(\vec{g}\times\vec{t})$ to $X$
  * $M_{view}=R_{view}T_{view}$
    * $T_{view}=\begin{bmatrix}1&0&0&-x_e\\0&1&0&-y_e\\0&0&1&-z_e\\0&0&0&1\end{bmatrix}$
    * $R_{view}^{-1}=\begin{bmatrix}x_{g\times t}&x_t&x_{-g}&0\\y_{g\times t}&y_t&y_{-g}&0\\z_{g\times t}&z_t&z_{-g}&0\\0&0&0&1\end{bmatrix}$
    * $R_{view}=(R_{view}^{-1})^T=\cdots$
      * $R_{-\theta}=R_\theta^T=R_\theta^{-1}\Longrightarrow旋转矩阵定义$

![未命名绘图.drawio.png](https://i.loli.net/2021/11/19/59zCv4uBXAWNQmf.png)

### Projection transformation

* #### Orthographic Projection
  * 映射到标准立方体，保留原有比例
  * Map a cuboid $[l,r] \times [b,t] \times \mathbf{[f,n]}$
  * **Canonical** **(正则,规范,标准)** cube $[-1,1]^3$
  * Translate & Scale
  * $M_{ortho}=\begin{bmatrix}\frac{2}{r-l}&0&0&0\\0&\frac{2}{t-b}&0&0\\0&0&\frac{2}{n-f}&0\\0&0&0&1\end{bmatrix}\begin{bmatrix}1&0&0&-\frac{r+l}{2}\\0&1&0&-\frac{t+b}{2}\\0&0&1&-\frac{n+f}{2}\\0&0&0&1\end{bmatrix}$

![ortho.png](https://i.loli.net/2021/11/19/8hVZQxPUDs3ukdp.png)

* #### Perspective Projection
  * 近大远小；失去平行关系，会聚到同一点
  * First, squish **frustum** into cuboid $(M_{persp\rightarrow ortho})$, then do orthographic transformaiton
    * Only $\mathbf{z}$ on surface $\mathbf{n}$ and $\mathbf{f}$ is **const**

![frustum.png](https://i.loli.net/2021/11/19/oIYEsQD4JBvcyOG.png)

  * Using similar triangle : $\begin{pmatrix}x\\y\\z\\1\end{pmatrix}\Rightarrow\begin{pmatrix}nx/z\\ny/z\\unknown\\1\end{pmatrix}==\begin{pmatrix}nx\\ny\\unknown\\z\end{pmatrix}$
    * Using 1st and 2nd row : $M_{persp\rightarrow ortho}=\begin{pmatrix}n&0&0&0\\0&n&0&0\\\cdots&\cdots&\cdots&\cdots\\0&0&1&0\end{pmatrix}$
  * Choose $\begin{pmatrix}x\\y\\n\\1\end{pmatrix}$ on surface $\mathbf{n}$ and $\begin{pmatrix}0\\0\\f\\1\end{pmatrix}$ on surface $\mathbf{f}$
    * $\begin{pmatrix}x\\y\\n\\1\end{pmatrix}==\begin{pmatrix}nx\\ny\\n^2\\n\end{pmatrix};\begin{pmatrix}0\\0\\f\\1\end{pmatrix}==\begin{pmatrix}0\\0\\f^2\\f\end{pmatrix}$
    * The 3rd **row** : $\begin{cases}\begin{pmatrix}0&0&A&B\end{pmatrix}\begin{pmatrix}x\\y\\n\\1\end{pmatrix}=n^2\\\begin{pmatrix}0&0&A&B\end{pmatrix}\begin{pmatrix}0\\0\\f\\1\end{pmatrix}=f^2\end{cases}$
    * Solution : $A=n+f; B=-nf$
