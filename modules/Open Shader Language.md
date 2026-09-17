## 💡New Idea: Scripting shaders in Blender
- Introduction of Open Shading Language (Amazing Spider Man)
- Example shaders
```c
shader test_shader(
    input vector norm,
    output color out_color = color(0,0,0)
    ){
    vector light_direction = vector(1/sqrt(2), 1/sqrt(2), 0);
    float intensity = dot(light_direction, norm);
    out_color = intensity * color(1,0,0);
}
```