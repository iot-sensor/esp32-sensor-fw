# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS main.c
    INCLUDE_DIRS  "../components/bme280" "../components/include" "../components/i2c"
    PRIV_INCLUDE_DIRS   
    REQUIRES     bme280 driver       
    PRIV_REQUIRES
)
