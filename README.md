# template-fun
A collection of my experiments with templates.


## Specialization
Template specialization involves having special cases for specific template type(s). For example, `std::vector<T>` has a specialization for when `T` is of type `bool`, where each bool occupies one bit. The example below is a full specialization where `n` is of type `size_t`. Full specialization refers to having a specialization for all template parameters. If the `fact` struct had some other template parameter(s), e.g. `template <typename T, size_t n> //...` then it would a partial specialization.

``` cpp
template <size_t n>
struct fact {
	constexpr static auto value = n * fact<n - 1>::value;
};
```

## TODO
* Declaration order dependency
* Stream tee
