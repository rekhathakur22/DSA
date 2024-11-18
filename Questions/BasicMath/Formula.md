# Modular Arithmetic Formula

$$
(a + b) \mod M = \left( (a \mod M) + (b \mod M) \right) \mod M
$$

$$
(a \cdot b) \mod M = \left( (a \mod M) \cdot (b \mod M) \right) \mod M
$$

$$
 (a - b) \mod M = \left( (a \mod M) - (b \mod M) \quad + \quad M \right) \mod M
$$

*Note:* The extra \(+ M\) is added to avoid negative numbers in the result.

$$
(\frac{a}{b} )\mod M = \left( (a \mod M) \cdot (b^{-1} \mod M) \right) \mod M
$$
