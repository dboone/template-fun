# template-fun
A collection of my experiments with templates.


## Partial Specialization
Template partial specialization involves having a special case for specific template type(s). For example, `std::vector<T>` has a partial specialization for when `T` is of type `bool`, where each bool occupies one bit. The example below is a partial specialization where `n` is of type `size_t`.

``` cpp
template<size_t n>
struct fact {
	constexpr static auto value = n * fact<n - 1>::value;
};
```

## TODO
* Explicit specialization
* Declaration order dependency
* Stream tee
