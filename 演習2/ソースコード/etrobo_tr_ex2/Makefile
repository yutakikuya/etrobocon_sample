# nxtOSEKルートディレクトリ
NXTOSEK_ROOT = ../nxtOSEK

# ターゲット実行形式ファイル名
#TARGET = model_impl
TARGET = etrobo_tr_ex2

# インクルードパス
USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer

# ライブラリ
USER_LIB = nxtway_gs_balancer

# Cソースファイル
TARGET_SOURCES = balancer_param.c ScenarioTracer.c UI.c BalanceRunner.c TouchSensor.c GyroSensor.c Motor.c model_impl.c

# TOPPERS/ATK1(OSEK)設定ファイル
TOPPERS_OSEK_OIL_SOURCE = model_impl.oil

# 下記のマクロは変更しないでください
O_PATH ?= build

include $(NXTOSEK_ROOT)/ecrobot/ecrobot.mak
