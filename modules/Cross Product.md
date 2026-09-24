## 💡New Idea: Cross Products

The cross product is a fundamental vector operation in 3D computer graphics. Unlike the dot product (which returns a scalar), the cross product takes two 3D vectors and returns a **new 3D vector** that is **perpendicular (orthogonal)** to both input vectors.

---

## 1. Core Intuition & Geometric Meaning

Given two vectors $\mathbf{a}$ and $\mathbf{b}$ in 3D space, their cross product is written as $\mathbf{a} \times \mathbf{b}$.

* **Direction:** The resulting vector points perpendicular to the plane formed by $\mathbf{a}$ and $\mathbf{b}$. The direction follows the **Right-Hand Rule**:
  1. Point your index finger in the direction of vector $\mathbf{a}$.
  2. Point your middle finger in the direction of vector $\mathbf{b}$.
  3. Your thumb points in the direction of $\mathbf{a} \times \mathbf{b}$.

* **Magnitude:** The magnitude (length) of the cross product represents the **area of the parallelogram** spanned by $\mathbf{a}$ and $\mathbf{b}$:

$$\Vert{}\mathbf{a} \times \mathbf{b}\Vert{} = \Vert{}\mathbf{a}\Vert{} \Vert{}\mathbf{b}\Vert{} \sin(\theta)$$

where $\theta$ is the angle between $\mathbf{a}$ and $\mathbf{b}$.

---

## 2. Algebraic Definition (3D Component Formula)

Given two 3D vectors:
$$\mathbf{a} = \begin{pmatrix} a_x \\ a_y \\ a_z \end{pmatrix}, \quad \mathbf{b} = \begin{pmatrix} b_x \\ b_y \\ b_z \end{pmatrix}$$

The cross product $\mathbf{c} = \mathbf{a} \times \mathbf{b}$ is computed as:

$$\mathbf{a} \times \mathbf{b} = \begin{pmatrix} a_y b_z - a_z b_y \\ a_z b_x - a_x b_z \\ a_x b_y - a_y b_x \end{pmatrix}$$

### Determinant Memory Trick
You can remember this formula using the 3x3 determinant form with unit basis vectors $\mathbf{i}, \mathbf{j}, \mathbf{k}$:

$$\mathbf{a} \times \mathbf{b} = \det \begin{pmatrix} \mathbf{i} & \mathbf{j} & \mathbf{k} \\ a_x & a_y & a_z \\ b_x & b_y & b_z \end{pmatrix}$$

---

## 3. Key Properties

1. **Anti-commutative:** 
   $$\mathbf{a} \times \mathbf{b} = -(\mathbf{b} \times \mathbf{a})$$
   *(Swapping inputs reverses the resulting vector's direction)*

2. **Non-associative:**
   $$\mathbf{a} \times (\mathbf{b} \times \mathbf{c}) \neq (\mathbf{a} \times \mathbf{b}) \times \mathbf{c}$$

3. **Parallel Vectors Yield Zero:**
   If $\mathbf{a}$ and $\mathbf{b}$ are parallel or anti-parallel ($\theta = 0^\circ$ or $180^\circ$), then $\mathbf{a} \times \mathbf{b} = \mathbf{0}$.

4. **Self Cross Product:**
   $$\mathbf{a} \times \mathbf{a} = \mathbf{0}$$

---

## 4. Step-by-Step Worked Example

Let's compute the cross product of $\mathbf{a} = \begin{pmatrix} 1 \\ 2 \\ 3 \end{pmatrix}$ and $\mathbf{b} = \begin{pmatrix} 4 \\ 5 \\ 6 \end{pmatrix}$:

1. **Calculate X component:**
   $$c_x = (a_y \cdot b_z) - (a_z \cdot b_y) = (2 \cdot 6) - (3 \cdot 5) = 12 - 15 = -3$$

2. **Calculate Y component:**
   $$c_y = (a_z \cdot b_x) - (a_x \cdot b_z) = (3 \cdot 4) - (1 \cdot 6) = 12 - 6 = 6$$

3. **Calculate Z component:**
   $$c_z = (a_x \cdot b_y) - (a_y \cdot b_x) = (1 \cdot 5) - (2 \cdot 4) = 5 - 8 = -3$$

**Result:**
$$\mathbf{a} \times \mathbf{b} = \begin{pmatrix} -3 \\ 6 \\ -3 \end{pmatrix}$$

*(Verification check: $\mathbf{a} \cdot \mathbf{c} = 1(-3) + 2(6) + 3(-3) = 0$, confirming orthogonality).*

---

## 5. Applications in Computer Graphics

* **Surface Normal Computation:** Given a triangle with vertices $P_0, P_1, P_2$, calculate edge vectors $\mathbf{u} = P_1 - P_0$ and $\mathbf{v} = P_2 - P_0$. The surface normal vector is:
  $$\mathbf{N} = \text{normalize}(\mathbf{u} \times \mathbf{v})$$

* **Constructing Orthonormal Bases (ONB):** Given a camera view direction $\mathbf{w}$, we construct a local coordinate frame $(u, v, w)$ by taking cross products with an arbitrary up-vector.

* **Back-Face Culling & Winding Order:** The sign of the cross product in screen space indicates whether a polygon's vertices are oriented clockwise or counter-clockwise.

---
