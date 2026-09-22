## 💡New Idea: Scripting shaders in Blender
- Introduction of Open Shading Language (Amazing Spider Man)
- Example shaders
```c
shader CustomShader(
   
    output color out_color = color(0,0,0)
    ){
    color ambient_light = color(.05,.05,.05);
    vector light_direction = vector(1,0,0);
    vector norm = N;
    float dot_product = max(0, dot(light_direction, norm));
    
    out_color = dot_product * color(1, 0, 0)+ambient_light;

}
```
