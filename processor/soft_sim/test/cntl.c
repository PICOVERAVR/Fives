/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "cntl.src" instead.
 */

#include <check.h>

#line 1 "cntl.src"
#include "test.h"
	
	

START_TEST(nop)
{
#line 8
    proc *p = calloc(1, sizeof(proc)); // important to make sure no stray bytes are different
    proc_set_vec(p);

    proc *p2 = malloc(sizeof(proc));
    proc_set_vec(p2);

    int code = instr_nop(p2);

    ck_assert_int_eq(code, RET_OK);
    ck_assert_int_eq(memcmp(p2, p, sizeof(proc)), 0); // make sure it did nothing

}
END_TEST

START_TEST(stop)
{
#line 20
	SETUP_M();

    int code = instr_stop(p);
    ck_assert_int_eq(code, RET_STOP);
	
}
END_TEST

START_TEST(load_basic1)
{
#line 28
	SETUP_M();
	
	p->regfile[R3] = 0xFF01;
	p->i.e_imm = 0xDEAD;
	instr_ldi(p);
	ck_assert_int_eq(p->regfile[R3], 0xFFAD);
	
}
END_TEST

START_TEST(load_full)
{
#line 36
	SETUP_M();
	uint16_t ram[8];
	ram[0] = 42;

	p->i.f_pm = 0b011;
	p->i.d_s = R0;
	p->i.d_d = R3;

	instr_ldr(p, ram);
	ck_assert_int_eq(p->regfile[R3], 42);
	ck_assert_int_eq(ram[0], 42); // check for modification

}
END_TEST

START_TEST(store_full)
{
#line 49
	SETUP_M();
	uint16_t ram[8];
	p->regfile[R1] = 42;

	p->i.f_pm = 0b011;
	p->i.d_s = R1;
	p->i.d_d = R0;

	instr_str(p, ram);
	ck_assert_int_eq(ram[0], 42);
	ck_assert_int_eq(p->regfile[R1], 42); // check for modification

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("cntl-check");
    TCase *tc1_1 = tcase_create("cntl");
    TCase *tc1_2 = tcase_create("load");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, nop);
    tcase_add_test(tc1_1, stop);
    suite_add_tcase(s1, tc1_2);
    tcase_add_test(tc1_2, load_basic1);
    tcase_add_test(tc1_2, load_full);
    tcase_add_test(tc1_2, store_full);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
