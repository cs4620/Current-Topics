## 💡New Idea: Ray Tracing
- We want to send ray into the scene
- We render a pixel at a time instead of a triangle at a time (rasterizing)

## 🖼️Activity:
- Consider a simple ray tracing setup with one triangle:
- We have a camera with an origin at [0,0,-1]
- We have a camera center target at [0, 0, 0]
- We have a camera field of view that extends from -1 to 1 in x and y when it reaches z=-1

- There are w=h pixels across the final image we are rendering to.


## 👩‍💻Code Together:
1. We need the following functions for vectors in order to build this ray tracer
  - add
  - subtract
  - scale
  - dot
  - cross
  - length
  - normalize
2. For each pixel in the final image, to send a ray through that pixel
  - We find where that ray will collide with the Z-plane
  - We normalize the result to get a direction
3. We need to find where the ray collides with the plane that the triangle defines
  - A plane can be defined as $Ax+By+Cz+D=0$ where $A$, $B$, and $C$ are the normal of the triangle
  - This $D$, the planes distance from the origin, can be found by negating the dot product of any point on the plane and the plane's normal.
    - Since each of the points in the triangle definition are in the plane, we can use that 
  - Once we have the definition of the plane, we can find where the ray through the pixel collides with the plane:
    - $N\cdot(o+r\cdot T)+D=0$
    - $N\cdot(o+r\cdot T)=-D$
    - $o\cdot N+r\cdot N\cdot T=-D$
    - $r\cdot N\cdot T=-D-o\cdot N$
    - $T=(-D-o\cdot N)/(r\cdot N)$
4. Once we have $T$, we can find the collision point as $o+r\cdot T$.
