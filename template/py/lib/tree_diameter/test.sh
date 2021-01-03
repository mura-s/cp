#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual=`echo "$input" | python main.py`

    if [ "$actual" != "$expected" ]; then
        echo "WA"
        echo "expected:"
        echo "$expected"
        echo
        echo "actual:"
        echo "$actual"
        echo

        all_ac=false
        return
    fi
    echo "AC"
    echo
}

# test cases
echo "[Sample1]"
input1="$(cat << EOS
4
0 1 2
1 2 1
1 3 3
EOS
)"
expected1="$(cat << EOS
5
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4
0 1 1
1 2 2
2 3 4
EOS
)"
expected2="$(cat << EOS
7
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
1024
0 1 867
1 2 697
2 3 576
3 4 762
4 5 146
5 6 563
6 7 821
7 8 157
8 9 272
9 10 181
10 11 999
11 12 580
12 13 166
13 14 637
14 15 895
15 16 234
16 17 343
17 18 169
18 19 745
19 20 532
20 21 517
21 22 855
22 23 717
23 24 787
24 25 698
25 26 116
26 27 123
27 28 579
28 29 613
29 30 329
30 31 745
31 32 596
32 33 950
33 34 579
34 35 785
35 36 433
36 37 829
37 38 680
38 39 956
39 40 93
40 41 734
41 42 695
42 43 655
43 44 484
44 45 338
45 46 668
46 47 467
47 48 157
48 49 163
49 50 747
50 51 882
51 52 392
52 53 605
53 54 851
54 55 823
55 56 927
56 57 215
57 58 555
58 59 674
59 60 512
60 61 896
61 62 202
62 63 843
63 64 28
64 65 209
65 66 116
66 67 255
67 68 613
68 69 917
69 70 280
70 71 402
71 72 988
72 73 172
73 74 931
74 75 329
75 76 939
76 77 66
77 78 700
78 79 872
79 80 123
80 81 457
81 82 97
82 83 495
83 84 811
84 85 701
85 86 760
86 87 549
87 88 141
88 89 480
89 90 980
90 91 965
91 92 105
92 93 168
93 94 357
94 95 842
95 96 843
96 97 336
97 98 112
98 99 449
99 100 366
100 101 517
101 102 677
102 103 722
103 104 733
104 105 773
105 106 409
106 107 190
107 108 588
108 109 194
109 110 579
110 111 831
111 112 880
112 113 527
113 114 200
114 115 876
115 116 383
116 117 740
117 118 447
118 119 250
119 120 47
120 121 794
121 122 279
122 123 801
123 124 859
124 125 662
125 126 470
126 127 923
127 128 947
128 129 63
129 130 717
130 131 941
131 132 885
132 133 208
133 134 93
134 135 121
135 136 723
136 137 500
137 138 503
138 139 860
139 140 199
140 141 549
141 142 11
142 143 339
143 144 949
144 145 291
145 146 123
146 147 670
147 148 95
148 149 815
149 150 488
150 151 625
151 152 783
152 153 278
153 154 52
154 155 209
155 156 112
156 157 117
157 158 16
158 159 318
159 160 231
160 161 705
161 162 413
162 163 661
163 164 194
164 165 103
165 166 42
166 167 567
167 168 247
168 169 763
169 170 941
170 171 429
171 172 693
172 173 971
173 174 837
174 175 850
175 176 279
176 177 18
177 178 314
178 179 486
179 180 576
180 181 399
181 182 492
182 183 153
183 184 68
184 185 84
185 186 458
186 187 86
187 188 376
188 189 628
189 190 113
190 191 38
191 192 670
192 193 8
193 194 513
194 195 868
195 196 3
196 197 299
197 198 508
198 199 847
199 200 543
200 201 374
201 202 295
202 203 393
203 204 180
204 205 425
205 206 745
206 207 622
207 208 650
208 209 842
209 210 738
210 211 748
211 212 234
212 213 11
213 214 923
214 215 672
215 216 615
216 217 88
217 218 663
218 219 782
219 220 699
220 221 45
221 222 367
222 223 569
223 224 158
224 225 462
225 226 994
226 227 722
227 228 416
228 229 275
229 230 791
230 231 438
231 232 576
232 233 727
233 234 896
234 235 338
235 236 807
236 237 559
237 238 307
238 239 879
239 240 445
240 241 607
241 242 119
242 243 416
243 244 185
244 245 284
245 246 21
246 247 185
247 248 713
248 249 671
249 250 313
250 251 448
251 252 457
252 253 196
253 254 643
254 255 388
255 256 366
256 257 560
257 258 707
258 259 402
259 260 588
260 261 707
261 262 606
262 263 175
263 264 4
264 265 934
265 266 921
266 267 692
267 268 973
268 269 300
269 270 594
270 271 23
271 272 339
272 273 387
273 274 624
274 275 619
275 276 69
276 277 560
277 278 757
278 279 513
279 280 60
280 281 667
281 282 775
282 283 708
283 284 695
284 285 357
285 286 807
286 287 346
287 288 286
288 289 816
289 290 595
290 291 403
291 292 382
292 293 691
293 294 509
294 295 443
295 296 468
296 297 539
297 298 157
298 299 865
299 300 619
300 301 94
301 302 733
302 303 737
303 304 874
304 305 453
305 306 4
306 307 350
307 308 489
308 309 494
309 310 271
310 311 300
311 312 534
312 313 809
313 314 801
314 315 550
315 316 62
316 317 606
317 318 541
318 319 978
319 320 428
320 321 808
321 322 592
322 323 428
323 324 871
324 325 176
325 326 118
326 327 951
327 328 276
328 329 367
329 330 803
330 331 849
331 332 809
332 333 831
333 334 939
334 335 941
335 336 817
336 337 866
337 338 139
338 339 372
339 340 593
340 341 967
341 342 402
342 343 197
343 344 809
344 345 43
345 346 74
346 347 655
347 348 194
348 349 948
349 350 871
350 351 250
351 352 395
352 353 330
353 354 976
354 355 519
355 356 350
356 357 93
357 358 737
358 359 327
359 360 669
360 361 749
361 362 874
362 363 486
363 364 623
364 365 964
365 366 630
366 367 947
367 368 304
368 369 280
369 370 824
370 371 796
371 372 981
372 373 78
373 374 167
374 375 938
375 376 285
376 377 354
377 378 407
378 379 442
379 380 766
380 381 930
381 382 188
382 383 340
383 384 72
384 385 579
385 386 724
386 387 862
387 388 494
388 389 312
389 390 149
390 391 80
391 392 186
392 393 575
393 394 509
394 395 250
395 396 626
396 397 959
397 398 516
398 399 539
399 400 19
400 401 764
401 402 589
402 403 637
403 404 683
404 405 189
405 406 583
406 407 981
407 408 947
408 409 19
409 410 465
410 411 442
411 412 969
412 413 519
413 414 876
414 415 395
415 416 335
416 417 86
417 418 376
418 419 852
419 420 817
420 421 763
421 422 604
422 423 242
423 424 275
424 425 438
425 426 795
426 427 759
427 428 273
428 429 359
429 430 497
430 431 766
431 432 633
432 433 355
433 434 665
434 435 403
435 436 955
436 437 821
437 438 713
438 439 134
439 440 738
440 441 739
441 442 445
442 443 616
443 444 472
444 445 296
445 446 664
446 447 881
447 448 142
448 449 276
449 450 871
450 451 912
451 452 94
452 453 841
453 454 377
454 455 347
455 456 998
456 457 104
457 458 231
458 459 732
459 460 422
460 461 238
461 462 803
462 463 323
463 464 869
464 465 444
465 466 45
466 467 505
467 468 771
468 469 651
469 470 633
470 471 742
471 472 346
472 473 959
473 474 806
474 475 638
475 476 912
476 477 501
477 478 462
478 479 329
479 480 77
480 481 150
481 482 629
482 483 861
483 484 767
484 485 555
485 486 588
486 487 647
487 488 743
488 489 836
489 490 834
490 491 211
491 492 267
492 493 626
493 494 954
494 495 729
495 496 559
496 497 442
497 498 39
498 499 515
499 500 355
500 501 596
501 502 797
502 503 63
503 504 92
504 505 2
505 506 896
506 507 604
507 508 591
508 509 841
509 510 168
510 511 371
511 512 429
512 513 947
513 514 934
514 515 312
515 516 999
516 517 72
517 518 956
518 519 604
519 520 431
520 521 277
521 522 602
522 523 533
523 524 459
524 525 304
525 526 345
526 527 300
527 528 598
528 529 375
529 530 975
530 531 604
531 532 115
532 533 886
533 534 697
534 535 695
535 536 665
536 537 610
537 538 963
538 539 80
539 540 248
540 541 347
541 542 958
542 543 177
543 544 147
544 545 309
545 546 126
546 547 364
547 548 681
548 549 294
549 550 756
550 551 611
551 552 591
552 553 680
553 554 458
554 555 100
555 556 491
556 557 115
557 558 517
558 559 246
559 560 274
560 561 730
561 562 833
562 563 375
563 564 249
564 565 884
565 566 497
566 567 346
567 568 535
568 569 151
569 570 162
570 571 717
571 572 481
572 573 842
573 574 158
574 575 980
575 576 303
576 577 923
577 578 171
578 579 770
579 580 475
580 581 603
581 582 78
582 583 800
583 584 570
584 585 243
585 586 896
586 587 158
587 588 692
588 589 445
589 590 639
590 591 644
591 592 199
592 593 183
593 594 325
594 595 331
595 596 296
596 597 758
597 598 412
598 599 750
599 600 373
600 601 832
601 602 849
602 603 739
603 604 59
604 605 927
605 606 213
606 607 859
607 608 240
608 609 226
609 610 543
610 611 983
611 612 121
612 613 387
613 614 556
614 615 443
615 616 88
616 617 120
617 618 207
618 619 268
619 620 815
620 621 678
621 622 311
622 623 514
623 624 679
624 625 893
625 626 474
626 627 986
627 628 956
628 629 115
629 630 837
630 631 201
631 632 790
632 633 321
633 634 451
634 635 932
635 636 870
636 637 205
637 638 457
638 639 345
639 640 575
640 641 725
641 642 867
642 643 224
643 644 111
644 645 574
645 646 355
646 647 855
647 648 205
648 649 818
649 650 522
650 651 328
651 652 141
652 653 410
653 654 902
654 655 683
655 656 27
656 657 625
657 658 499
658 659 365
659 660 946
660 661 894
661 662 420
662 663 221
663 664 904
664 665 58
665 666 598
666 667 50
667 668 943
668 669 605
669 670 20
670 671 232
671 672 403
672 673 624
673 674 529
674 675 947
675 676 687
676 677 890
677 678 848
678 679 855
679 680 542
680 681 611
681 682 639
682 683 914
683 684 706
684 685 16
685 686 214
686 687 17
687 688 229
688 689 207
689 690 403
690 691 37
691 692 884
692 693 301
693 694 858
694 695 741
695 696 634
696 697 77
697 698 591
698 699 635
699 700 312
700 701 663
701 702 262
702 703 822
703 704 573
704 705 434
705 706 891
706 707 762
707 708 299
708 709 129
709 710 403
710 711 96
711 712 786
712 713 927
713 714 869
714 715 432
715 716 398
716 717 310
717 718 208
718 719 189
719 720 59
720 721 239
721 722 348
722 723 53
723 724 867
724 725 120
725 726 818
726 727 920
727 728 883
728 729 180
729 730 277
730 731 715
731 732 804
732 733 268
733 734 399
734 735 475
735 736 792
736 737 359
737 738 633
738 739 451
739 740 28
740 741 871
741 742 784
742 743 921
743 744 828
744 745 312
745 746 525
746 747 730
747 748 313
748 749 379
749 750 769
750 751 260
751 752 912
752 753 587
753 754 199
754 755 948
755 756 262
756 757 413
757 758 513
758 759 42
759 760 164
760 761 28
761 762 278
762 763 367
763 764 342
764 765 304
765 766 493
766 767 765
767 768 211
768 769 91
769 770 801
770 771 92
771 772 801
772 773 220
773 774 541
774 775 247
775 776 484
776 777 67
777 778 547
778 779 90
779 780 50
780 781 286
781 782 161
782 783 54
783 784 438
784 785 476
785 786 791
786 787 882
787 788 128
788 789 287
789 790 862
790 791 163
791 792 661
792 793 319
793 794 901
794 795 356
795 796 69
796 797 693
797 798 815
798 799 161
799 800 98
800 801 408
801 802 833
802 803 46
803 804 892
804 805 348
805 806 300
806 807 237
807 808 475
808 809 707
809 810 786
810 811 79
811 812 268
812 813 276
813 814 728
814 815 763
815 816 18
816 817 243
817 818 633
818 819 524
819 820 679
820 821 383
821 822 28
822 823 280
823 824 971
824 825 441
825 826 150
826 827 956
827 828 759
828 829 301
829 830 822
830 831 455
831 832 221
832 833 672
833 834 82
834 835 523
835 836 606
836 837 265
837 838 393
838 839 232
839 840 708
840 841 977
841 842 187
842 843 807
843 844 734
844 845 784
845 846 773
846 847 188
847 848 546
848 849 243
849 850 288
850 851 28
851 852 130
852 853 930
853 854 131
854 855 854
855 856 845
856 857 126
857 858 977
858 859 998
859 860 281
860 861 784
861 862 490
862 863 920
863 864 715
864 865 852
865 866 592
866 867 107
867 868 885
868 869 533
869 870 93
870 871 463
871 872 437
872 873 180
873 874 451
874 875 513
875 876 829
876 877 4
877 878 323
878 879 10
879 880 380
880 881 226
881 882 166
882 883 374
883 884 979
884 885 838
885 886 654
886 887 548
887 888 629
888 889 165
889 890 625
890 891 916
891 892 864
892 893 806
893 894 487
894 895 694
895 896 98
896 897 625
897 898 48
898 899 710
899 900 900
900 901 807
901 902 216
902 903 953
903 904 873
904 905 113
905 906 113
906 907 727
907 908 785
908 909 471
909 910 552
910 911 941
911 912 100
912 913 477
913 914 799
914 915 271
915 916 275
916 917 387
917 918 677
918 919 224
919 920 81
920 921 298
921 922 554
922 923 780
923 924 576
924 925 687
925 926 740
926 927 960
927 928 756
928 929 723
929 930 747
930 931 693
931 932 56
932 933 50
933 934 740
934 935 855
935 936 966
936 937 864
937 938 777
938 939 614
939 940 642
940 941 410
941 942 74
942 943 748
943 944 376
944 945 857
945 946 921
946 947 225
947 948 932
948 949 461
949 950 802
950 951 209
951 952 455
952 953 643
953 954 142
954 955 421
955 956 998
956 957 607
957 958 204
958 959 113
959 960 564
960 961 160
961 962 385
962 963 533
963 964 436
964 965 309
965 966 820
966 967 1
967 968 530
968 969 103
969 970 51
970 971 453
971 972 23
972 973 340
973 974 695
974 975 605
975 976 1
976 977 757
977 978 681
978 979 45
979 980 832
980 981 459
981 982 896
982 983 924
983 984 701
984 985 261
985 986 493
986 987 330
987 988 836
988 989 439
989 990 403
990 991 940
991 992 419
992 993 372
993 994 281
994 995 998
995 996 507
996 997 558
997 998 851
998 999 237
999 1000 198
1000 1001 284
1001 1002 292
1002 1003 754
1003 1004 283
1004 1005 636
1005 1006 991
1006 1007 625
1007 1008 205
1008 1009 659
1009 1010 722
1010 1011 315
1011 1012 145
1012 1013 752
1013 1014 69
1014 1015 314
1015 1016 684
1016 1017 699
1017 1018 265
1018 1019 742
1019 1020 730
1020 1021 143
1021 1022 949
1022 1023 597
EOS
)"
expected3="$(cat << EOS
519829
EOS
)"
try "$input3" "$expected3"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"