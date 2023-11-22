use std::ops::{AddAssign, DivAssign, MulAssign, SubAssign};

pub mod matrix;
pub mod ops;
pub mod vector;

pub trait Scalar: Copy + AddAssign + SubAssign + MulAssign + DivAssign + Sized + PartialEq + PartialOrd {
    const ZERO: Self;
    const ONE: Self;
}

impl Scalar for f64 {
    const ZERO: Self = 0.0;
    const ONE: Self = 1.0;
}