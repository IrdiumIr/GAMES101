# GAMES101-Lecture6
## Rasterization 2 (Antialiasing and Z-Buffering)
>### References
>* Chapter8 The Graphics Pipeline(8.2.3)
>* Chapter9 Signal Processing
***

## Main Topics
* Anti(-)aliasing : ***(抗锯齿 / 反走样)***
  * Sampling theory
  * Antialiasing in practice
* Visibility / occlusion
  * Z-buffering

## Antialiasing

* ### Sampling theory
  * Sampling Artifacts (aliasing)
    * Jaggies – sampling in space
    * Moire – undersampling images
    * Wagon wheel effect – sampling in time
    * ...
  * Reason behind artifacts
    * signals changing too fast **(high frequency)** while sampling too slowly
  * **Blurring** (Pre-Filtering) Before sampling
    * cannot change order

* ### Frequency Domain
  * Fourier Transform
    * $f(x)\Rightarrow F(\omega)$
    * spatial domain $\Rightarrow$ frequency domain
  * Higher Frequencies Need Faster Sampling
    * Otherwise it will lose signals
  * Undersampling Creates Frequency Aliases
    * The same sampling cannot distinguish different $f$

* ### Filtering
  * **Getting rid of** certain frequency contents
  * Different filtering :
    * High-pass filter (filter out low $f$)
      * left with **edges**
    * Low-pass filter (filter out high $f$)
      * Blur
    * filter out some high & low $f$
      * mixture
  * Filtering = Convolution ***(卷积)*** (= Averaging)
    * Definition : 取周围平均 (相乘求和)
    * spatial domain (convolution) $\Rightarrow$ frequency domain (multiplication) **$vice\ \ versa$**
      * Operation1 : convolution
      * Operation2 : $F(\omega)\Rightarrow Multiplication\Rightarrow f(x)$
  * Box Filter
    * Low-pass filter
    * spatial domain **enlarges** while $f$ domain **lessens** 

* ### Sampling
  * Sampling = Repeating frequency contents
    * 使用冲激函数采样 $\Rightarrow$ 在频域上重复被采样函数
  * Aliasing = Mixed frequency contents
    * sample too slow with time interval increases then $f$ interval decreases so it overlaps

* ### Antialiasing
  * Option1 : Increase sampling rate
  * Option2 : **Antialiasing**
    * Making Fourier contents “narrower” before repeating
    * Filtering out **high frequencies** before sampling

* ### A Practical Pre-Filter
  * 1 pixel-width box filter
    * low-pass, blurring
    * averaging values in pixel area
      * Convolve $f(x,y)$ by a 1-pixel box-blur 
      * Then sample at every pixel’s center
  * SuperSampling : ***MSAA***
    * sampling multiple locations within a pixel
    * divide 1 pixel into $N\times N$
    * Average them inside exach pixel
    * Cost : *Great Calculation*
    * Solution : 
      * 不使用均匀采样
      * 部分采样复用
  * FXAA
    * **Fast** Approximate
    * 先获得有锯齿的图,再后处理去除锯齿. (找到边界)
  * TAA
    * Tem ' poral
    * 时序信息,借助前面帧的信息.相邻两帧同一像素用不同的位置来sample
  * SS
    * Super resolution / super sampling
    * From *low* resolution to *high* resolution
    * DLSS (**Deep Learning** Super Sampling) : Guess!

## Visibility / occlusion

* ### Title
  * title1
    * title1.1
