import numpy as np
from scipy.interpolate import interp1d, CubicSpline
from numpy.polynomial.polynomial import Polynomial
import pandas as pd

# Given data
maturities = np.array([1, 2, 3, 5, 7, 10, 20, 30])  # Years
rates = np.array([4.25, 4.50, 4.60, 4.75, 4.20, 3.85, 4.10, 3.90])  # Percent
target_year = 8

# Linear Interpolation
linear_interp = interp1d(maturities, rates, kind='linear')
linear_result = linear_interp(target_year)

# Cubic Spline Interpolation
cubic_spline = CubicSpline(maturities, rates)
cubic_result = cubic_spline(target_year)

# Quadratic Curve Fitting
quadratic_fit = Polynomial.fit(maturities, rates, deg=2)
quadratic_result = quadratic_fit(target_year)

# Nearest Neighbor Interpolation
nearest_result = rates[np.abs(maturities - target_year).argmin()]

# Combine results into a dictionary
results = {
    "Linear Interpolation": linear_result,
    "Cubic Spline Interpolation": cubic_result,
    "Quadratic Curve Fitting": quadratic_result,
    "Nearest Neighbor Interpolation": nearest_result
}

# Display results in a DataFrame
results_df = pd.DataFrame.from_dict(results, orient='index', columns=['8-Year Yield Rate'])
print(results_df)
