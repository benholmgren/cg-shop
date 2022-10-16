# CG-SHOP 2023

## 2023 Computational Geometry Challenge Accompanying SoCG: Minimum Convex Cover

[Problem Description](https://cgshop.ibr.cs.tu-bs.de/competition/cg-shop-2022/#problem-description)

## Literature Review

### Relevant Hardness Results

[O'Rourke Original NP-Hardness Result](https://www.computational-geometry.org/documents/MinConvexCovers_Allerton_1982.pdf)
- Poses problem/Introduces Steiner points
- Canonical Reduction from 3-SAT

[Original NP-Hardness Result for Polygons Without Holes](https://www.math.ucdavis.edu/~deloera/MISC/LA-BIBLIO/trunk/Culberson.pdf)

[Extra Hardness of Convex Cover](https://arxiv.org/pdf/2106.02335.pdf)
- Not verifiable, uber hard!

### Heuristic Solutions

[Poly-time Approximation Algorithm](https://github.com/benholmgren/cg-shop/blob/main/papers/lit-review/approx-algo.pdf)
-  Uses configurations on a pairwise grid between vertices
-  Makes grid finer by redefining a grid among pairwise points between the original grid, etc
-  Bounds number of configurations, thereby bounding the number of possible interior convex polygons to try

[Near Linear Cover of Disjoint Polygons](https://arxiv.org/pdf/1912.03429.pdf)
- Given disjoint polygons, there exists a unique convexification which has total minimum area and covers all polygons
- Could use this simple technique to piece together remaining disjoint polygons after taking away large convex polygons initially



