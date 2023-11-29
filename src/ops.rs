use crate::Scalar;

pub fn vec_add_assign<S: Scalar>(lhs: &mut [S], rhs: &[S]) {
    debug_assert!(lhs.len() == rhs.len());

    for (l, &r) in lhs.iter_mut().zip(rhs.iter()) {
        *l += r;
    }
}

pub fn vec_sub_assign<S: Scalar>(lhs: &mut [S], rhs: &[S]) {
    debug_assert!(lhs.len() == rhs.len());

    for (l, &r) in lhs.iter_mut().zip(rhs.iter()) {
        *l -= r;
    }
}

pub fn vec_mul_assign<S: Scalar>(lhs: &mut [S], factor: S) {
    for l in lhs {
        *l *= factor;
    }
}

pub fn vec_div_assign<S: Scalar>(lhs: &mut [S], factor: S) {
    for l in lhs {
        *l /= factor;
    }
}

pub fn vec_fma<S: Scalar>(lhs: &mut [S], rhs: &[S], factor: S) {
    debug_assert!(lhs.len() == rhs.len());

    for (l, &r) in lhs.iter_mut().zip(rhs.iter()) {
        *l += r * factor;
    }
}

pub fn lerp<S: Scalar>(u: S, v: S, t: S) -> S {
    u * (S::ONE - t) + v * t
}

pub fn vec_dot<S: Scalar>(lhs: &[S], rhs: &[S]) -> S {
    debug_assert!(lhs.len() == rhs.len());

    lhs.iter()
        .zip(rhs.iter())
        .fold(S::ZERO, |acc, (&l, &r)| acc + l * r)
}

pub fn vec_norm_1<S: Scalar>(lhs: &[S]) -> S {
    lhs.iter().fold(S::ZERO, |acc, x| acc + x.norm())
}

pub fn vec_norm<S: Scalar>(lhs: &[S]) -> S {
    lhs.iter().fold(S::ZERO, |acc, x| acc + x.norm_sq()).sqrt()
}

pub fn vec_norm_inf<S: Scalar>(lhs: &[S]) -> S {
    lhs.iter().fold(
        S::ZERO,
        |acc, x| if acc < x.norm() { x.norm() } else { acc },
    )
}
