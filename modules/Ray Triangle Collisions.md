## 👩‍💻Code Together:
1. We need to find where the ray collides with the plane that the triangle defines
 - A plane can be defined as $Ax+By+Cz+D=0$ where $A$, $B$, and $C$ are the normal of the triangle
    - We can find the normal (or perpendicular vector), by taking the cross product of two of the edge of the triangle, i.e. $(t_1 - t_2)\times (t_3-t_2)$. We need to normalize this vector, so $ABC = |(t_1 - t_2)\times (t_3-t_2)|$
  - This `D`, the planes distance from the origin, can be found by negating the dot product of any point on the plane and the plane's normal.
    - Since each of the points in the triangle definition are in the plane, we can use any of the corners of the triangle
    - $D = -ABC\cdot t_1$
  - Once we have the definition of the plane, we can find where the ray through the pixel collides with the plane:
    - $ABC\cdot(cameraOrigin+rayDirection\cdot T)+D=0$
    - $ABC\cdot(cameraOrigin+rayDirection\cdot T)=-D$
    - $cameraOrigin\cdot ABC+rayDirection\cdot ABC\cdot T=-D$
    - $rayDirection\cdot ABC\cdot T=-D-cameraOrigin\cdot ABC$
    - $T=(-D-cameraOrigin\cdot ABC)/(rayDirection\cdot ABC)$
2. Once we have $T$, we can find the collision point as $collisionPoint = cameraOrigin+rayDirection\cdot T$.
3. Once we know where the ray intersects the plane, then we need to find whether that point is in the triangle.
   - (Note that there are many different ways to doing this.)
   - Find the Barycentric coordinate for the collision point.
   - If the coordinates all sum to 1, then we are in the triangle. Otherwise, we didn't hit this triangle
4. Once we know if a point is in the triangle, we assign it the triangel color. If it didn't hit the triangle, we assign the background color to the pixel
5. Once we know all the pixel colors, we write them to the final image.

- Instead of just assigning a color to each pixel, we can create a custom shader, just like in Blender or with OSL code.
