use matrix::{self, vector::Vector, matrix::Matrix};

const VALUE1: [f64; 4] = [3., 1., 4., 2.];
const VALUE2: [f64; 4] = [-5., 8., -7., 6.];

const ADDRES: [f64; 4] = [-2., 9., -3., 8.];
const SUBRES: [f64; 4] = [8., -7., 11., -4.];
const MULRES: [f64; 4] = [9., 3., 12., 6.];
const DIVRES: [f64; 4] = [1.5, 0.5, 2., 1.];

#[test]
fn basic_vec_ops() {
    let lhs = Vector::from_slice(&VALUE1);
    let rhs = Vector::from_slice(&VALUE2);

    let mut op = lhs.clone();
    op += &rhs;
    assert_eq!(op, Vector::from_slice(&ADDRES));

    op.assign(&lhs);
    op -= &rhs;
    assert_eq!(op, Vector::from_slice(&SUBRES));

    op.assign(&lhs);
    op *= 3.0;
    assert_eq!(op, Vector::from_slice(&MULRES));

    op.assign(&lhs);
    op /= 2.0;
    assert_eq!(op, Vector::from_slice(&DIVRES));
}

#[test]
fn basic_mat_ops() {
    let lhs = Matrix::from_slice(&VALUE1, 2);
    let rhs = Matrix::from_slice(&VALUE2, 2);

    let mut op = lhs.clone();
    op += &rhs;
    assert_eq!(op, Matrix::from_slice(&ADDRES, 2));

    op.assign(&lhs);
    op -= &rhs;
    assert_eq!(op, Matrix::from_slice(&SUBRES, 2));

    op.assign(&lhs);
    op *= 3.0;
    assert_eq!(op, Matrix::from_slice(&MULRES, 2));

    op.assign(&lhs);
    op /= 2.0;
    assert_eq!(op, Matrix::from_slice(&DIVRES, 2));
}