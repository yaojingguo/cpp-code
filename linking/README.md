# Running
Use the following commands to run `test`

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./test
```

# Note
The linking of `test` needs the `.so` file. One possible read is that `test` needs to
contains the file name of the shared library. 

```
readelf -d test

Dynamic section at offset 0xe18 contains 25 entries:
  Tag        Type                         Name/Value
 0x0000000000000001 (NEEDED)             Shared library: [libgreeting.so]
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
```

But I think that the file name of `.so` is enough for the linker to work if the
linker does not check the presence of the referred function.

And running `test` also needs the `.so` file.
