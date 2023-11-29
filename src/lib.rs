use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign};

pub mod matrix;
pub mod ops;
pub mod vector;

pub trait Scalar:
    Copy
    + Add<Output = Self>
    + AddAssign
    + Sub<Output = Self>
    + SubAssign
    + Mul<Output = Self>
    + MulAssign
    + Div<Output = Self>
    + DivAssign
    + Sized
    + PartialEq
    + PartialOrd
{
    const ZERO: Self;
    const ONE: Self;

    fn norm(self) -> Self;
    fn norm_sq(self) -> Self;
    fn sqrt(self) -> Self;
}

impl Scalar for f64 {
    const ZERO: Self = 0.0;
    const ONE: Self = 1.0;

    fn norm(self) -> Self {
        self.abs()
    }

    fn norm_sq(self) -> Self {
        self * self
    }

    fn sqrt(self) -> Self {
        f64::sqrt(self)
    }
}
