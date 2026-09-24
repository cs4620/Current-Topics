# Diffuse Lighting & Lambertian Reflectance

Diffuse lighting models dull, non-shiny surfaces (like matte paint, chalk, or raw wood) that scatter light evenly in all directions. Unlike specular reflection, diffuse reflection looks the same regardless of where the observer/camera is positioned.

---

## 1. Core Intuition & Lambert's Cosine Law

The intensity of light reflected off a matte surface depends on the **angle of incidence**—how directly the light strikes the surface.

* **Direct Hit ($\theta = 0^\circ$):** When light strikes perpendicular to a surface, the photons are concentrated over a small area, making the surface bright.
* **Glancing Angle ($\theta \to 90^\circ$):** As the angle increases, the same bundle of light spreads over a larger surface area, diluting its brightness.
* **Graze/Behind Surface ($\theta \ge 90^\circ$):** The surface faces away from the light source and receives zero direct illumination.

### Lambert's Cosine Law
The radiant intensity reflected from an ideal diffuse surface is directly proportional to the cosine of the angle $\theta$ between the light direction vector $\mathbf{L}$ and the surface normal vector $\mathbf{N}$:

$$I_{\text{diffuse}} \propto \cos(\theta)$$

---

## 2. Vector Formulation

In practice, we avoid computing expensive trigonometric functions ($\arccos$ or $\cos$) by taking advantage of the **dot product**.

For two unit vectors $\hat{\mathbf{N}}$ and $\hat{\mathbf{L}}$:

$$\hat{\mathbf{N}} \cdot \hat{\mathbf{L}} = \Vert{}\hat{\mathbf{N}}\Vert{} \Vert{}\hat{\mathbf{L}}\Vert{} \cos(\theta) = (1)(1)\cos(\theta) = \cos(\theta)$$

### Key Vector Definitions
* $\hat{\mathbf{N}}$: **Unit Normal Vector** perpendicular to the surface at the point being shaded.
* $\hat{\mathbf{L}}$: **Unit Light Vector** pointing from the surface position **toward** the light source.

### The Clamped Dot Product
Since light cannot be negative when facing away from a surface ($\theta > 90^\circ \implies \cos(\theta) < 0$), we clamp the dot product at zero using `max()`:

$$I_{\text{diffuse}} = \max(\hat{\mathbf{N}} \cdot \hat{\mathbf{L}}, 0.0)$$

---

## 3. Full Diffuse Equation

Combining light color, surface albedo (base color), and light intensity gives the final RGB color equation:

$$C_{\text{diffuse}} = k_d \cdot I_{\text{light}} \cdot \max(\hat{\mathbf{N}} \cdot \hat{\mathbf{L}}, 0.0)$$

Where:
* $k_d$ is the diffuse albedo/material color (RGB tuple, e.g., red vector $(1.0, 0.0, 0.0)$).
* $I_{\text{light}}$ is the color/intensity of the light source (RGB tuple).
* $\hat{\mathbf{N}} \cdot \hat{\mathbf{L}}$ scales the brightness based on orientation.

---

## 4. Step-by-Step Worked Example

Suppose a point on a surface has:
* Surface Normal: $\mathbf{N} = \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix}$ (pointing straight up)
* Light Position: $P_{\text{light}} = \begin{pmatrix} 3 \\ 4 \\ 0 \end{pmatrix}$
* Surface Position: $P_{\text{surface}} = \begin{pmatrix} 0 \\ 0 \\ 0 \end{pmatrix}$
* Material Color ($k_d$): $\begin{pmatrix} 0.8 \\ 0.2 \\ 0.2 \end{pmatrix}$ (Matte Red)
* Light Color ($I_{\text{light}}$): $\begin{pmatrix} 1.0 \\ 1.0 \\ 1.0 \end{pmatrix}$ (White)

### 1. Compute and normalize the light direction vector $\hat{\mathbf{L}}$:
$$\mathbf{L} = P_{\text{light}} - P_{\text{surface}} = \begin{pmatrix} 3 \\ 4 \\ 0 \end{pmatrix}$$

$$\Vert{}\mathbf{L}\Vert{} = \sqrt{3^2 + 4^2 + 0^2} = 5$$

$$\hat{\mathbf{L}} = \frac{\mathbf{L}}{\Vert{}\mathbf{L}\Vert{}} = \begin{pmatrix} 0.6 \\ 0.8 \\ 0.0 \end{pmatrix}$$

### 2. Compute the orientation factor ($\hat{\mathbf{N}} \cdot \hat{\mathbf{L}}$):
$$\hat{\mathbf{N}} \cdot \hat{\mathbf{L}} = (0 \cdot 0.6) + (1 \cdot 0.8) + (0 \cdot 0.0) = 0.8$$

Since $0.8 > 0$, $\max(0.8, 0.0) = 0.8$.

### 3. Calculate final diffuse color:
$$C_{\text{diffuse}} = \begin{pmatrix} 0.8 \\ 0.2 \\ 0.2 \end{pmatrix} \odot \begin{pmatrix} 1.0 \\ 1.0 \\ 1.0 \end{pmatrix} \cdot 0.8 = \begin{pmatrix} 0.64 \\ 0.16 \\ 0.16 \end{pmatrix}$$

---
## 👩‍💻Activity: Add Diffuse Lighting in Blender
- Look at different light types
  - Spot
  - Sun
  - Point
  - Area
    - Why do area lights cause noise in the rendered image?
