// 负责对象的构造和析构
// 提供construct和destroy两个方法
// Created by Administrator on 2020/10/30.
//

#ifndef ZSTL_CONSTRUCT_HPP
#define ZSTL_CONSTRUCT_HPP

#include <new>

namespace zstl
{
    //构造对象

    template<typename T>
    void construct(T* p)
    {
        ::new((void*)p) T();
    }

    template<typename T1, typename T2>
    void construct(T1* p, T2& val)
    {
        ::new((void*)p) T1(val);
    }

    template<typename T, typename... Args>
    void construct(T* p, Args&&... args)
    {
        ::new((void*)p) T();
    }
}

#endif //ZSTL_CONSTRUCT_HPP
