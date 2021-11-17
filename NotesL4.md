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
  * $\mathbf{R}(\mathbf{n},\alpha)=\cdots$
* ### Reflection
    - $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}-1&0\\0&1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$
    - Y ( and X ) axis symmetry
* ### Shear
    - $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}1&a\\0&1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$
    - Horizontal shift $=0$ at $y=0$
    - Horizontal shift $=a$ at $y=1$
    - Vertical shift always $=0$
* ### Rotate
    - origin $(0,0)$ , **CCW** by default
    - $R_\theta=\begin{bmatrix}\cos\theta&-\sin\theta\\\sin\theta&\cos\theta\end{bmatrix}$
* ### Linear Transforms = Matrices
    - $X'=MX$
    - $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}a&b\\c&d\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$

## Homogeneous coordinates
* Why Homogeneous coordinates
* Affine transformation ***(仿射变换)***
* ### Translation
    - $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}a&b\\c&d\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}+\begin{bmatrix}t_x\\t_y\end{bmatrix}$
    - Translation is **NOT** linear transform
* ### Homogeneous coordinates
    - Add 3rd coordinate(dimension)
        - $2D\ point = (x,y,1)^T$
        - $2D\ vector = (x,y,0)^T$
    - $\begin{pmatrix}x'\\y'\\w'\end{pmatrix}=\begin{pmatrix}1&0&t_x\\0&1&t_y\\0&0&1\end{pmatrix}\begin{pmatrix}x\\y\\1\end{pmatrix}=\begin{pmatrix}x+t_x\\y+t_y\\1\end{pmatrix}$
    - $\begin{pmatrix}x\\y\\w\end{pmatrix}\Rightarrow\begin{pmatrix}x/w\\y/w\\1\end{pmatrix}(w\neq0,for\ 2D\ point)$
* ### Affine Translation
    - $\begin{pmatrix}x'\\y'\\1\end{pmatrix}=\begin{pmatrix}a&b&t_x\\c&d&t_y\\0&0&1\end{pmatrix}\begin{pmatrix}x\\y\\1\end{pmatrix}$
    - $Affine map = linear map + translation$
* ### Inverse Transform
  - $M^{-1}$

## (De)Composite Translation
* Transform Ordering Matters!
* $A_n(...A_2(A_1(\mathbf{x})))=\mathbf{A_n}\cdots\mathbf{A_2}\cdot\mathbf{A_1}\cdot\begin{pmatrix}x\\y\\1\end{pmatrix}$
    - ***Accelerat calculation***
* Rotate around point $C$
    - Translate to origin $O$
    - Rotate
    - Translate back to $C$
    - $T(-c)\rightarrow R(\alpha)\rightarrow T(c) \Longrightarrow T(c)\cdot R(\alpha)\cdot T(-c)$

## 3D Transformations
* Add 4rd coordinate(dimension)
    - $3D\ point = (x,y,z,1)^T$
    - $3D\ vector = (x,y,z,0)^T$
* 3D Affine translation
    - $\begin{pmatrix}x'\\y'\\z'\\1\end{pmatrix}=\begin{pmatrix}a&b&c&t_x\\d&e&f&t_y\\g&h&i&t_z\\0&0&0&1\end{pmatrix}\begin{pmatrix}x\\y\\z\\1\end{pmatrix}$




---

MVP：

- Model transformation (placing objects)
    
    想象一下：世界坐标系下有很多Object，用一个变化矩阵把它们的顶点坐标从Local坐标系（相对）转换到世界Global坐标系（绝对）。这就是placing objects
    
- View transformation (placing camera)
    
    想象一下：我们看到的画面由摄像机捕捉，摄像机参数决定了我们在屏幕上看到的东西，这一步可以将世界坐标系转换到摄像机坐标系。
    
- Projection transformation
    
    摄像机坐标系，视锥体，再规整一下
    

Viewing (观测) transformation

- View (视图) / Camera transformation
- Projection (投影) transformation
    - Orthographic projection (cuboid to “canonical” cube [-1, 1]^3)
    - Perspective projection (frustum to “canonical” cube)
        - First “squish” the frustum into a cuboid
        - Then Do orthographic projection

---

向量以一列的矩阵表示（nx1）

矩阵(nxn)表示变换，在向量左边，左乘

- 旋转：绕某个轴旋转某个角度
    - 轴：向量，六个自由度（由两个点确定一条直线）
    - 角度：值
    - 绕经过原点的轴：Rodrigues’ Rotation Formula：
        
        $$\mathbf{R}(\mathbf{n}, \alpha)=\cos (\alpha) \mathbf{I}+(1-\cos (\alpha)) \mathbf{n} \mathbf{n}^{T}+\sin (\alpha)\left(\begin{array}{ccc} 0 & -n_{z} & n_{y} \\ n_{z} & 0 & -n_{x} \\ -n_{y} & n_{x} & 0 \end{array}\right)$$
        
    - 绕空间中任意轴旋转：[三维空间绕任意轴旋转矩阵的推导 - 知乎](https://zhuanlan.zhihu.com/p/56587491)
        - 记得哪本书里看见过……
- 平移：三个自由度
- 缩放：三个自由度

若绕静坐标系（世界坐标系）旋转，则左乘，也是变换矩阵坐标矩阵；若是绕动坐标系旋转（自身建立一个坐标系），则右乘，也就是坐标矩阵变换矩阵。 即，左乘是相对于坐标值所在的坐标系（世界坐标系）下的三个坐标轴进行旋转变换。而右乘则是以当前点为旋转中心，进行旋转变换。