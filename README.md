### build and install myLib
run this in 'myLib/build'

```sh
mkdir build && cd build && cmake .. && cmake --build . && cmake --install . --prefix . && cd ..
```

### use myLib
run this in 'use_my_lib_in_another_project/build'

```sh
mkdir build && cd build && cmake .. -DCMAKE_INSTALL_PREFIX=../../myLib/build/  && cmake --build . && cd ..
```
