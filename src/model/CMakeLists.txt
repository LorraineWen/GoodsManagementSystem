# 设置库文件
aux_source_directory(./models MODELS_LIB) 
aux_source_directory(./dao DAO_LIB)
add_library(modellib SHARED ${MODELS_LIB} ${DAO_LIB})