use std::ops::{AddAssign, DivAssign, MulAssign, SubAssign};

use crate::ops;
use crate::Scalar;

#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Vector<S: Scalar> {
    inner: Vec<S>,
}

impl<S: Scalar> Vector<S> {
    pub fn new(size: usize) -> Self {
        Self {
            inner: vec![S::ZERO; size],
        }
    }

    pub fn from_slice(data: &[S]) -> Self {
        Self {
            inner: data.to_vec(),
        }
    }

    pub fn assign(&mut self, rhs: &Self) {
        debug_assert!(self.size() == rhs.size());
        self.inner.copy_from_slice(rhs.as_slice())
    }

    pub fn size(&self) -> usize {
        self.inner.len()
    }

    pub fn resize(&mut self, size: usize) {
        self.inner.resize(size, S::ZERO)
    }

    pub fn as_slice(&self) -> &[S] {
        self.inner.as_slice()
    }

    pub fn as_mut_slice(&mut self) -> &mut [S] {
        self.inner.as_mut_slice()
    }

    pub fn lerp_assign(&mut self, v: &Self, t: S) {
        *self *= S::ONE - t;
        ops::vec_fma(self.as_mut_slice(), v.as_slice(), t);
    }

    pub fn dot(&self, v: &Self) -> S {
        ops::vec_dot(self.as_slice(), v.as_slice())
    }
}

impl<S: Scalar> AddAssign<&Self> for Vector<S> {
    fn add_assign(&mut self, rhs: &Self) {
        ops::vec_add_assign(self.as_mut_slice(), rhs.as_slice())
    }
}

impl<S: Scalar> SubAssign<&Self> for Vector<S> {
    fn sub_assign(&mut self, rhs: &Self) {
        ops::vec_sub_assign(self.as_mut_slice(), rhs.as_slice())
    }
}

impl<S: Scalar> MulAssign<S> for Vector<S> {
    fn mul_assign(&mut self, rhs: S) {
        ops::vec_mul_assign(self.as_mut_slice(), rhs)
    }
}

impl<S: Scalar> DivAssign<S> for Vector<S> {
    fn div_assign(&mut self, rhs: S) {
        ops::vec_div_assign(self.as_mut_slice(), rhs)
    }
}

pub fn linear_combination<S: Scalar>(u: &[Vector<S>], coefs: &[S]) -> Vector<S> {
    debug_assert!(u.len() == coefs.len());

    let (first_u, u) = u.split_first().unwrap();
    let (&first_coef, coefs) = coefs.split_first().unwrap();

    let mut result = first_u.clone();

    result *= first_coef;

    for (v, &k) in u.iter().zip(coefs.iter()) {
        ops::vec_fma(result.as_mut_slice(), v.as_slice(), k);
    }

    result
}
