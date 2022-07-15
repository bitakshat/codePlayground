```
def q_lerp(value: float, ease: float):
	"""convert a linear value to an eased value according to the smoothness (0->1)"""
	return pow(value, ease) / (pos(value, ease) + pow(1-value, ease))
```
