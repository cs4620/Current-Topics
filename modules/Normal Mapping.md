## 💡New Idea: Normal Maps
- A normal map in an additional "texture" that can be added to a material. It hints to the renderer how the normal should change for every pixel. 
- This allows a high level of surface detail without needing to add actual geometry.
- Notably this does not provide detail when the normal map is viewed obliquely.
- The planet generation scene in the *Wrath of Khan* is an early example of normal mapping being used in film
  - The company that created this effect would later be renamed *Pixar*.
  - https://www.youtube.com/watch?v=Tq_sSxDE32c
  - This clip is also notable for its use of procedural generation
  
## Example
- Here is the normal map for bricks from [Poly Haven](polyhaven.com).
- ![Brick Normal Map](../images/red_brick_nor_dx_4k.png)
- Here is the difference when rendering a 2 triangle plane without a normal map (left) and with a normal map (right)
- ![Normal Map Comparison](./Normal%20Maps/Normal%20Map%20Comparison.png)