```
## Term, thing, concept
> Short, concise definition
Code example, math example, algorithm
Philosophy: every singe word count
```

## **Smart Pointer**
>
> Wrappers around basic pointers with automated logic (memory management) via RAII.

### 1. `std::unique_ptr`
>
> Exclusive ownership: only one pointer can own the resource. Cannot be copied, only moved.

```cpp
auto p = std::make_unique<int>(10);
// std::unique_ptr<int> p2 = p;         // Error: No copying
std::unique_ptr<int> p2 = std::move(p); // Works: p is now null, p2 owns data

```

### 2. `std::shared_ptr`

> Shared ownership: multiple pointers point to one resource. Resource deleted when the last pointer is destroyed (Reference Counting).

```cpp
auto s1 = std::make_shared<int>(20);
auto s2 = s1; // Both own data; reference count = 2

```

### 3. `std::weak_ptr`

> Non-owning observer: points to data managed by shared_ptr without increasing reference count. Used to break circular dependencies.

---

# Move Semantics & Rvalue References

## **lvalue**

> An object that occupies an identifiable location in memory (it has an address).

## **rvalue**

> A temporary value that does not have a persisting memory address (e.g., literals or temporary results).

## **rvalue reference (&&)**

> A reference type that can bind to an rvalue, allowing the programmer to "steal" its resources before it is destroyed.

## **Move Semantics**

> Transferring internal resources (pointers, buffers) from a temporary object to a new one instead of performing a deep copy.

```cpp
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2 = std::move(v1); // v2 "steals" v1's memory; v1 is now empty

```

---

# Type Safety & Type Inference

## **Type Safety**

> Preventing errors by ensuring operations only occur between compatible types. Strengthened by `enum class` and `nullptr`.

## **Type Inference**

> The compiler deduces the variable type from its initializer at compile-time.

```cpp
auto x = 5;            // int
auto y = 5.5;          // double
const auto& z = x;     // const int&

```

---

# Lambdas & Functional Programming

## **Lambdas**

> Anonymous, inline functions that can capture variables from their surrounding scope.

```cpp
// [capture](params) -> return_type { body }
auto add = [](int a, int b) { return a + b; };
int factor = 2;
auto multiply = [factor](int n) { return n * factor; };

```

---

# Compile-time Programming

## **`constexpr`**

> Specifies that a value or function can be evaluated at compile-time, shifting computation from runtime to the compiler.

```cpp
constexpr int square(int n) { return n * n; }
int arr[square(5)]; // Array size is a compile-time constant

```

---

# Standard Library

## **`std::optional`**
>
> A wrapper for a value that may or may not exist. Replaces "magic numbers" or error codes.

## **`std::string_view`**
>
> A lightweight, non-owning reference to a string. Fast for parsing as it avoids memory allocation.

```cpp
void print(std::string_view sv) { std::cout << sv << "\n"; }

```
