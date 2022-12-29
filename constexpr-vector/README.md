# Constexpr Vector

I've always been interested in the compile-time capabilities of C++, and it always seemed overly and unecessarily extensive to accomplish simple things, like producing an array of filtered values (usable at run time).

Largely this stems from the fact that std::array needs to be initialised with a length, so no matter how you did it, you'd have to initialise a max amount of space. But with the introduction of constexpr vector in C++20, I thought this would potentially change. Hence the experimentation.

Now, after playing with it - I think right now, and this ight be due largely to lackluster compiler support of the feature, but the way you are required to do it now, is tedious and convoluted. Hopefully this improves with time, but a variable length container at ocmpile time is cool none-the-less.

### One more thing...

This doesn't compile on clang, and it looks like clang doesn't support constexpr vectors at all yet, which is unfortunate. However, it does compile on gcc.
