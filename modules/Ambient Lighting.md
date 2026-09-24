## 💡New Idea: Ambient Lighting
- Light is always bouncing around us. Ambient lighting is a 'fudge' term that tries to capture this reflected light.
- Real light keeps bouncing: a red wall tints the floor next to it, the floor tints the ceiling, and so on.
- Simulating all of those bounces is called **global illumination**, and it is expensive.
- Ambient light collapses all of those bounces into a single constant term. (Remember: everything in graphics is a simplification.)
- Ambient light is *direction-independent*. Every surface receives the same amount no matter which way its normal points or where the camera is.
  - That is why it is so cheap.
  - That is also why it looks flat.
- If ambient light is so 'wrong', why did games use it for decades? (It costs almost nothing to compute.)

## 💡New Idea: The Lighting Equation
- The classic lighting model adds three terms together: `final color = ambient + diffuse + specular`
- We will see this in code when we write our own shader in [Open Shading Language](./Open%20Shader%20Language.md):
  - `out_color = dot_product * color(1, 0, 0) + ambient_light;`
  - The `ambient_light` constant is the term from this module. The `dot_product` term is [Diffuse Lighting](./Diffuse%20Lighting.md).

## 💡New Idea: What Ambient Light Can't Do
- Ambient light can never cast a shadow. Why? (It arrives from everywhere equally, so there is nothing to block.)
- The corner test: in real life the corners of a room look darker, but not with pure ambient light. Why? (In a corner, the walls block most of the bouncing light.)
- A scene lit only by ambient light looks flat and 'CG'. This is a big reason early computer graphics looked fake.
- **Ambient occlusion (AO)** is a hack on top of the hack: it darkens creases, crevices, and places where objects touch to fake the blocked light.

## 💡New Idea: Ambient Light Has Color
- Ambient light is rarely neutral white:
  - A clear day outdoors: bluish ambient light from the sky
  - Sunset: warm orange ambient light
  - Night: cool moonlight blue
- The color of the ambient light does a lot to set the mood of a scene (lighting is story telling!)

## 💡New Idea: Better Approximations of Bounced Light
- Flat ambient color (Blender: World tab, Background color and strength)
- Hemisphere lighting: sky color from above, ground color from below
- HDRI environment textures: an image wrapped around the scene lights it from every direction. This is image-based lighting, the modern 'ambient light'.
- Path tracing (Cycles) computes the real bounces that ambient light fakes. See [Introduction to Ray Tracing Renderers](./Introduction%20to%20Ray%20Tracing%20Renderers.md).

## 👩‍💻Activity: Ambient Light
- Adjust the ambient lighting in Blender (World tab, Surface, Background)
  - Change the color and the strength
- Delete every light in the scene and render. The scene is still visible! That is ambient light.
- Compare three renders of the same scene:
  - Ambient light only
  - A single point light only
  - Both together
  - Which one looks the most 'real'? Why?
- Tint the ambient light to set a mood: a horror scene, a sunny meadow, a moonlit night
- Put a sphere in the corner where two planes meet and render in Cycles. Cycles computes real bounced light, so the corner darkens. A flat ambient color can never do this.
- Swap the flat world color for a free HDRI from [Poly Haven](https://polyhaven.com/hdris) and rotate it. How much more 'real' does the scene feel?


> [!Tip] History Moment
> Early FPS games only used ambient lighting. For example look at [Wolfenstein 3D](https://www.youtube.com/watch?v=MnjXHOApVIc), the predecessor to Doom.
> - [Doom](https://www.youtube.com/watch?v=Q4GiCg_m8wA) (1993) improved on this with per-sector light levels, still flat ambient but varying by region
> - [Quake](https://www.youtube.com/watch?v=Ir-6wFAgSSI) (1996) baked lightmaps into the level, the first mainstream approximation of bounced light
> - Crysis (2007) popularized screen-space ambient occlusion (SSAO) in real-time games, a hack on top of the hack 