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
            inner: data.to_vec()
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
