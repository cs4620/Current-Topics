## 🖼️Activity:
- Look at wavefront technology:
- [Star Trek: Voyager Opening Credits](https://www.youtube.com/watch?v=uDaOYj2wggg)
- [Twister Tornadoes](https://www.youtube.com/watch?v=HmNiJjCbeqg)

# 🖼️Activity
- Comparing different export formats
  - [OBJ - Human Readable](https://en.wikipedia.org/wiki/Wavefront_.obj_file)
  - [FBX - Common for games](https://code.blender.org/2013/08/fbx-binary-file-format-specification/)
  - [USD - The new and shiny format for film](https://www.pixar.com/openusd)
  - 
  - 

## 💡New Idea: OBJ Files
- You only need to pay attention to the following lines:
  - v (three floats that define the x, y, and z of a vertex location)
  - vt (two floats that define the u, and v of a vertex texture coordinate)
  - vn (three floats that define the x, y, and z of a vertex normal)
  - f (three triples in `v_index/vt_index/vn_index` format that define the three vertices in a triangle)
- Indices are 1-based instead of the traditional 0-based used across computer science

- You can ignore everything else

- Example OBJ file for a triangle
  - Note that this example excludes lines we should ignore
```obj
v 0.000000 0.000000 0.000000
v 1.000000 0.000000 0.000000
v 0.000000 1.000000 0.000000
vn -0.0000 -0.0000 1.0000
vt 0.000000 0.000000
f 3/1/1 1/1/1 2/1/1
```

- Example for a (slightly) more complex shape
  - Note that this example includes lines we should ignore
```obj
# Blender 5.1.0
# www.blender.org
o Cube
v -1.000000 -1.000000 -1.000000
v -1.000000 -1.000000 1.000000
v 1.000000 -1.000000 -1.000000
v 1.000000 -1.000000 1.000000
v 1.000000 1.000000 -1.000000
v 1.000000 1.000000 1.000000
vn 1.0000 -0.0000 -0.0000
vn -0.0000 -1.0000 -0.0000
vt 0.625000 0.500000
vt 0.375000 0.750000
vt 0.375000 0.500000
vt 0.625000 0.750000
vt 0.375000 1.000000
vt 0.625000 1.000000
s 0
f 6/1/1 3/2/1 5/3/1
f 4/4/2 1/5/2 3/2/2
f 6/1/1 4/4/1 3/2/1
f 4/4/2 2/6/2 1/5/2
```

  
## 👩‍💻Code Together:
- OBJ

## 💡New Idea: OBJ File Export
- Tips for exporting from blender:
  - Check the Forward Axis and Up Axis
    - Recommended: Forward Axis set to Y and Up Axis set to Z
  - Turn on Geometry->Triangulated Mesh
    - Otherwise you might not get everything as triangles.
- You do not need to import material properties from blender
  - You are welcome to as something that goes above and beyond, but it is not required
- You do not need to import multiple objects from blender
  - You are welcome to as something that goes above and beyond, but it is not required
- You can simplify your blender project so that it works better when importing
  - For example, combining objects or reducing geometry count.
- You do not need to import animation from blender
  - You are welcome to as something that goes above and beyond, but it is not required
- **Do not debug your OBJ importer with a complex mesh.**
  - Start with a simple mesh (i.e. one triangle) and then slowly expand (i.e. to a cube) until your code can handle a large mesh.