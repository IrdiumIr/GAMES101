# GAMES101-Lecture2
## Review of Linear Algebra
>### References
>* Chapter2 Miscellaneous Math
>* Chapter5 Linear Algebra
***
## Graphics' Dependencies
* Basic Mathematics
    - Linear Algebra, Calculus, Statistics
* Basic Physics
    - Optics, Mechanics
* Misc
    - Signal processing
    - Numerical analysis
* Aesthetics(美学)
## Vectors
* 向量的定义，归一化，求和，坐标表示，长度
* ***Dot product***
    - $\vec{a}\cdot\vec{b}=\parallel\vec{a}\parallel\parallel\vec{b}\parallel\cos\theta$
    - $\cos\theta=\hat{a}\cdot\hat{b}$ (*for unit vectors*)
* Dot product in Graphics
    - Find angle between vectors($\cos\theta$ between light src & surface)
    - Find **projection** of one vector on another
    - Measure how close 2 directions are
    - Decompose a vector
    - Determind fowward / backward(dot product > or < 0)
* Dot product for projection
    - $\vec{b}_\perp$ : **Projection** of $\vec{b}$ onto $\vec{a}$
    - $\vec{b}_\perp=k\hat{a}=\parallel\vec{b}_\perp\parallel\hat{a}=\parallel\vec{b}\parallel\cos\theta\cdot\hat{a}$ *(along $\hat{a}$)*
* ***Cross product***
    - $\parallel\vec{a}\times\vec{b}\parallel=\parallel\vec{a}\parallel\parallel\vec{b}\parallel\sin\phi$
    - Cross product is **orthogonal** to 2 initial vectors
    - ***Right-Hand Rule***
        - Thumb direction
    - Determine left / right
      - $\vec{a}\times\vec{b}>0\Rightarrow\vec{b}$ is at left side of $\vec{a}$
    - Determine **inside / outside**
      - $\overrightarrow{AB}\times\overrightarrow{AP}>0\Rightarrow P$ is at left side of $AB$
      - $\overrightarrow{BC}\times\overrightarrow{BP}>0\Rightarrow P$ is at left side of $BC$
      - Also, $P$ is at left side of $CA$
      - Thus, $P$ is inside $\triangle ABC$
      - $P$ is always at **left / right** side of $AB/BC/CA$
## Matrices
* In Graphics, pervasively used to represent **transformations**
    - Translation, rotation, shear, scale 
* 矩阵乘法，分配，交换
* Matrix-Matrix Multiplication $\Rightarrow$ row from $A$ $\times$ column from $B$
* $(AB)^T=B^TA^T$
* $AA^{-1} =A^{-1}A=I$
* $(AB)^{-1}=B^{-1}A^{-1}$
* Cross product $\Rightarrow$ Matrix $\times$ Vector
    - $\vec{a}\times\vec{b}=A^*b=\begin{pmatrix}0&-{z_a}&y_a\\z_a&0&-{x_a}\\-{y_a}&x_a&0\\\end{pmatrix}\begin{pmatrix}x_b\\y_b\\z_b\end{pmatrix}$
