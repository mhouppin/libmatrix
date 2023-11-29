use matrix::{self, matrix::Matrix, ops::lerp, vector::Vector};

#[test]
fn basic_vec_ops() {
    let mut u = Vector::from_slice(&[2., 3.]);
    let v = Vector::from_slice(&[5., 7.]);
    u += &v;
    assert_eq!(u.as_slice(), &[7., 10.]);

    let mut u = Vector::from_slice(&[2., 3.]);
    u -= &v;
    assert_eq!(u.as_slice(), &[-3., -4.]);

    let mut u = Vector::from_slice(&[2., 3.]);
    u *= 2.;
    assert_eq!(u.as_slice(), &[4., 6.]);

    let mut u = Vector::from_slice(&[2., 3.]);
    u /= 2.;
    assert_eq!(u.as_slice(), &[1., 1.5]);
}

#[test]
fn basic_mat_ops() {
    let mut u = Matrix::from_slice(&[1., 2., 3., 4.], 2);
    let v = Matrix::from_slice(&[7., 4., -2., 2.], 2);
    u += &v;
    assert_eq!(u.as_slice(), &[8., 6., 1., 6.]);

    let mut u = Matrix::from_slice(&[1., 2., 3., 4.], 2);
    u -= &v;
    assert_eq!(u.as_slice(), &[-6., -2., 5., 2.]);

    let mut u = Matrix::from_slice(&[1., 2., 3., 4.], 2);
    u *= 2.;
    assert_eq!(u.as_slice(), &[2., 4., 6., 8.]);

    let mut u = Matrix::from_slice(&[1., 2., 3., 4.], 2);
    u /= 2.;
    assert_eq!(u.as_slice(), &[0.5, 1., 1.5, 2.]);
}

#[test]
fn linear_ops() {
    assert_eq!(lerp(0., 1., 0.), 0.);
    assert_eq!(lerp(0., 1., 1.), 1.);
    assert_eq!(lerp(0., 1., 0.5), 0.5);
    assert_eq!(lerp(21., 42., 0.25), 26.25);
}

#[test]
fn linear_vec_ops() {
    let e1 = Vector::from_slice(&[1., 0., 0.]);
    let e2 = Vector::from_slice(&[0., 1., 0.]);
    let e3 = Vector::from_slice(&[0., 0., 1.]);

    let v1 = Vector::from_slice(&[1., 2., 3.]);
    let v2 = Vector::from_slice(&[0., 10., -100.]);

    let l1 = matrix::vector::linear_combination(&[e1, e2, e3], &[10., -2., 0.5]);
    assert_eq!(l1.as_slice(), &[10., -2., 0.5]);

    let l2 = matrix::vector::linear_combination(&[v1, v2], &[10., -2.]);
    assert_eq!(l2.as_slice(), &[10., 0., 230.]);

    let mut u = Vector::from_slice(&[2., 1.]);
    let v = Vector::from_slice(&[4., 2.]);
    u.lerp_assign(&v, 0.25);
    assert_eq!(u.as_slice(), &[2.5, 1.25]);
}

#[test]
fn linear_mat_ops() {
    let mut u = Matrix::from_slice(&[2., 1., 3., 4.], 2);
    let v = Matrix::from_slice(&[20., 10., 30., 40.], 2);
    u.lerp_assign(&v, 0.5);
    assert_eq!(u.as_slice(), &[11., 5.5, 16.5, 22.]);
}

#[test]
fn vec_dot_ops() {
    let u = Vector::from_slice(&[0., 0.]);
    let v = Vector::from_slice(&[1., 1.]);
    assert_eq!(u.dot(&v), 0.);

    let u = Vector::from_slice(&[1., 1.]);
    assert_eq!(u.dot(&v), 2.);

    let u = Vector::from_slice(&[-1., 6.]);
    let v = Vector::from_slice(&[3., 2.]);
    assert_eq!(u.dot(&v), 9.);
}
