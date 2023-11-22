use crate::Scalar;

pub fn vec_add_assign<S: Scalar>(lhs: &mut [S], rhs: &[S]) {
    debug_assert!(lhs.len() == rhs.len());

    for (l, r) in lhs.iter_mut().zip(rhs.iter()) {
        *l += *r;
    }
}

pub fn vec_sub_assign<S: Scalar>(lhs: &mut [S], rhs: &[S]) {
    debug_assert!(lhs.len() == rhs.len());

    for (l, r) in lhs.iter_mut().zip(rhs.iter()) {
        *l -= *r;
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
