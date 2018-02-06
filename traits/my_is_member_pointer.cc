/// integral_constant
template<typename _Tp, _Tp __v>
struct integral_constant {
  static constexpr _Tp                  value = __v;
  typedef _Tp                           value_type;
  typedef integral_constant<_Tp, __v>   type;
  constexpr operator value_type() const noexcept { return value; }
#if __cplusplus > 201103L

#define __cpp_lib_integral_constant_callable 201304

  constexpr value_type operator()() const noexcept { return value; }
#endif
};

typedef integral_constant<bool, false>    false_type;

template<typename _Tp>
struct __is_member_pointer_helper : public false_type {};

template<typename _Tp, typename _Cp>
struct __is_member_pointer_helper<_Tp _Cp::*> : public true_type {};

/// is_member_pointer
template<typename _Tp>
struct is_member_pointer : public __is_member_pointer_helper<typename remove_cv<_Tp>::type>::type {};

