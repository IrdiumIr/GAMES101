# GAMES101-Lecture3
## Transformation

***
## Main Topics
* Why Transformation
    - Modeling
    - Viewing
* 2D Transformaitons
* Homogeneous coordinates ***(齐次坐标)***
## 2D Transformations
* Representing transformations using matrices
* Rotation, scale, shear
* ### Scale
    - $\begin{bmatrix}x'\\y'\end{bmatrix}=\begin{bmatrix}S_x&0\\0&S_y\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}$
    - Uniform / Non-Uniform *($S_x=or\neq S_y$)*
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
