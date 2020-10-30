// 提供通用工具 move forward swap等
// Created by Administrator on 2020/10/30.
//

#ifndef ZSTL_UTIL_HPP
#define ZSTL_UTIL_HPP

#include <cstddef>

namespace zstl
{
    // move
    // 因为模板类型参数T可能会推导为T&,
    // 为了保证结果返回一个右值引用，因此需要将T的引用属性给去了
    // static_cast是因为不能直接让右值引用绑定一个左值，但可以将左值强转为右值引用
    template<typename T>
    typename std::remove_reference<T>::type&& move(T&& rhs)
    {
        return static_cast<typename std::remove_reference<T>::type&&>(rhs);
    }

    // forward
    template<typename T>
    T&& forward(typename std::remove_reference<T>::type& rhs)
    {
        return static_cast<T&&>(rhs);
    }

    template<typename T>
    T&& forward(typename std::remove_reference<T>::type&& rhs)
    {
        return static_cast<T&&>(rhs);
    }

    // swap
    template<typename T>
    void swap(T& lhs, T& rhs)
    {
        auto tmp{zstl::move(lhs)};
        lhs = zstl::move(rhs);
        rhs = zstl::move(tmp);
    }

    template<typename BeginIter1, typename BeginIter2>
    BeginIter2 swap_range(BeginIter1 begin1, BeginIter1 end1, BeginIter2 begin2)
    {
        for(; begin1 != end1; ++begin1, (void)++begin2)
        {
            zstl::swap(*begin1, *begin2);
        }
        return begin2;
    }

    template<typename T, size_t N, int t = 0>
    void swap(T (&lhs)[N], T (&rhs)[N])
    {
        swap_range(lhs, rhs + N, rhs);
    }

    // pair

}

#endif //ZSTL_UTIL_HPP
