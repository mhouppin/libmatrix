use std::ops::{AddAssign, DivAssign, MulAssign, SubAssign};

use crate::ops;
use crate::Scalar;

#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Matrix<S: Scalar> {
    inner: Vec<S>,
    col_count: usize,
}

impl<S: Scalar> Matrix<S> {
    pub fn new(row_count: usize, col_count: usize) -> Self {
        Self {
            inner: vec![S::ZERO; row_count * col_count],
            col_count
        }
    }

    pub fn from_slice(data: &[S], col_count: usize) -> Self {
        debug_assert!(col_count != 0);
        debug_assert!(data.len() % col_count == 0);
        Self {
            inner: data.to_vec(),
            col_count
        }
    }

    pub fn assign(&mut self, rhs: &Self) {
        debug_assert!(self.size() == rhs.size());
        debug_assert!(self.col_count() == rhs.col_count());
        self.inner.copy_from_slice(rhs.as_slice())
    }

    pub fn size(&self) -> usize {
        self.inner.len()
    }

    pub fn row_count(&self) -> usize {
        self.size() / self.col_count
    }

    pub fn col_count(&self) -> usize {
        self.col_count
    }

    pub fn resize(&mut self, row_count: usize, col_count: usize) {
        self.inner.resize(row_count * col_count, S::ZERO)
    }

    pub fn as_slice(&self) -> &[S] {
        self.inner.as_slice()
    }

    pub fn as_mut_slice(&mut self) -> &mut [S] {
        self.inner.as_mut_slice()
    }
}

impl<S: Scalar> AddAssign<&Self> for Matrix<S> {
    fn add_assign(&mut self, rhs: &Self) {
        debug_assert!(self.col_count == rhs.col_count);
        ops::vec_add_assign(self.as_mut_slice(), rhs.as_slice())
    }
}

impl<S: Scalar> SubAssign<&Self> for Matrix<S> {
    fn sub_assign(&mut self, rhs: &Self) {
        debug_assert!(self.col_count == rhs.col_count);
        ops::vec_sub_assign(self.as_mut_slice(), rhs.as_slice())
    }
}

impl<S: Scalar> MulAssign<S> for Matrix<S> {
    fn mul_assign(&mut self, rhs: S) {
        ops::vec_mul_assign(self.as_mut_slice(), rhs)
    }
}

impl<S: Scalar> DivAssign<S> for Matrix<S> {
    fn div_assign(&mut self, rhs: S) {
        ops::vec_div_assign(self.as_mut_slice(), rhs)
    }
}
