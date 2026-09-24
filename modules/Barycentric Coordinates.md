# Barycentric

- We can use Barycentric coordinates to go back and forth between the $x$, $y$, and $z$ coordinates of a position on a 3D triangle and the  the $u$ and $v$ coordinates on a 2D texture.

- Let's consider a triangle with points at $(0,0,0)$, $(6,0,0)$, and $(0,6,0)$. Note that this triangle is intentionally two-dimensional to help in visualizing this process. The math is the same for any arbitrary triangle, however

- Start by calculating the area of the triangle. The vectors that define the two legs are $(6,0,0)$ and $(0,6,0)$

- The cross product of these two vectors gives us the area of the parallelagram defined by the vectors. If we divide that amount by two, we get the area of the triangle.
   - $(6,0,0)\times(0,6,0)$
   - $x=0-0$
   - $y=0-0$
   - $z=36-0=36$
   - The length of the vector $(0,0,36)$ is $\sqrt{0^2+0^2+36^2}=36$
   - Thus the triangle Area = $36/2=18$

- If  the point in question is $P=(2,2,0)$, then we can calculate the $u,v$ coordinate as folows
   - $u=(P-B)\times (P-C)/36$
   - $v=(P-A)\times (P-C)/36$
   - $w=1-u-v$
   - $u=((-4,2,0)\times (2, -4,0))/36$
   - $v=((2, 2, 0)\times (2, -4,0))/36$
   - $w=1-u-v$


- This website interactively shows you how Barycentric coordinates change as you move the point in question: https://polygonalcube.itch.io/barycentric-coordinates-visualization
