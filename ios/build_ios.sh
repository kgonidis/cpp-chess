#! bash

pushd build
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/ios.toolchain.cmake -DPLATFORM=OS64 -GXcode ../../
cmake --build . --config Release --
popd