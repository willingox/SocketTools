/*
 Navicat Premium Data Transfer

 Source Server         : yun1
 Source Server Type    : MySQL
 Source Server Version : 50565
 Source Host           : 117.78.7.51:3306
 Source Schema         : shouzhenwuxian

 Target Server Type    : MySQL
 Target Server Version : 50565
 File Encoding         : 65001

 Date: 07/03/2021 10:43:57
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for bm
-- ----------------------------
DROP TABLE IF EXISTS `bm`;
CREATE TABLE `bm`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for c3p0testtable
-- ----------------------------
DROP TABLE IF EXISTS `c3p0testtable`;
CREATE TABLE `c3p0testtable`  (
  `a` char(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for clazz
-- ----------------------------
DROP TABLE IF EXISTS `clazz`;
CREATE TABLE `clazz`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `gradeId` int(11) NOT NULL,
  `name` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `remark` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `gradeId`(`gradeId`) USING BTREE,
  CONSTRAINT `clazz_ibfk_1` FOREIGN KEY (`gradeId`) REFERENCES `grade` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 19 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for curperson
-- ----------------------------
DROP TABLE IF EXISTS `curperson`;
CREATE TABLE `curperson`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for cwsr
-- ----------------------------
DROP TABLE IF EXISTS `cwsr`;
CREATE TABLE `cwsr`  (
  `f1` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f2` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f3` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f4` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f5` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f6` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f7` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f8` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f9` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f10` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f11` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f12` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f13` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f14` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f15` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f16` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `f17` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for cwsrmx
-- ----------------------------
DROP TABLE IF EXISTS `cwsrmx`;
CREATE TABLE `cwsrmx`  (
  `srid` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `pirce` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `num` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `txmc` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `zhekou` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `taoxi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for cwzc
-- ----------------------------
DROP TABLE IF EXISTS `cwzc`;
CREATE TABLE `cwzc`  (
  `zcid` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `price` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `num` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `beizhu` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `riqi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `caozuoren` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for czy
-- ----------------------------
DROP TABLE IF EXISTS `czy`;
CREATE TABLE `czy`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL,
  `password` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `keshi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL,
  `myright` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL,
  `introduce` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `bianma` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL,
  PRIMARY KEY (`bianma`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for devdata
-- ----------------------------
DROP TABLE IF EXISTS `devdata`;
CREATE TABLE `devdata`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `devID` int(11) NULL DEFAULT NULL COMMENT '设备id',
  `devtemper` float(255, 0) NULL DEFAULT NULL COMMENT '温度',
  `devwater` float(255, 0) NULL DEFAULT NULL COMMENT '湿度',
  `devwarning` int(255) NULL DEFAULT NULL COMMENT '告警标志',
  `devtime` datetime NULL DEFAULT NULL COMMENT '设备上送时间',
  `cursystime` datetime NULL DEFAULT NULL COMMENT '后台记录时间',
  `lowdianyawarningint` int(1) NULL DEFAULT NULL COMMENT 'bit7  低电压告警',
  `shebeiguzhang` int(255) NULL DEFAULT NULL COMMENT 'bit6 设备故障',
  `beiyong1` int(255) NULL DEFAULT NULL COMMENT 'bit5 ',
  `duandiangaojing` int(255) NULL DEFAULT NULL COMMENT 'bit4 断电告警',
  `beiyong2` int(255) NULL DEFAULT NULL COMMENT 'bit3',
  `beiyong3` int(255) NULL DEFAULT NULL COMMENT 'bit2',
  `shidugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit1',
  `wendugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit0',
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `devID`(`devID`, `devtime`, `cursystime`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 498510 CHARACTER SET = gbk COLLATE = gbk_chinese_ci COMMENT = '设备历史数据' ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for devdata_copy1
-- ----------------------------
DROP TABLE IF EXISTS `devdata_copy1`;
CREATE TABLE `devdata_copy1`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `devID` int(11) NULL DEFAULT NULL COMMENT '设备id',
  `devtemper` float(255, 0) NULL DEFAULT NULL COMMENT '温度',
  `devwater` float(255, 0) NULL DEFAULT NULL COMMENT '湿度',
  `devwarning` int(255) NULL DEFAULT NULL COMMENT '告警标志',
  `devtime` datetime NULL DEFAULT NULL COMMENT '设备上送时间',
  `cursystime` datetime NULL DEFAULT NULL COMMENT '后台记录时间',
  `lowdianyawarningint` int(1) NULL DEFAULT NULL COMMENT 'bit7  低电压告警',
  `shebeiguzhang` int(255) NULL DEFAULT NULL COMMENT 'bit6 设备故障',
  `beiyong1` int(255) NULL DEFAULT NULL COMMENT 'bit5 ',
  `duandiangaojing` int(255) NULL DEFAULT NULL COMMENT 'bit4 断电告警',
  `beiyong2` int(255) NULL DEFAULT NULL COMMENT 'bit3',
  `beiyong3` int(255) NULL DEFAULT NULL COMMENT 'bit2',
  `shidugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit1',
  `wendugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit0',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 13564 CHARACTER SET = gbk COLLATE = gbk_chinese_ci COMMENT = '设备历史数据' ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for devdatadeal
-- ----------------------------
DROP TABLE IF EXISTS `devdatadeal`;
CREATE TABLE `devdatadeal`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `devID` int(11) NULL DEFAULT NULL COMMENT '设备id',
  `devtemper` float(255, 0) NULL DEFAULT NULL COMMENT '温度',
  `devwater` float(255, 0) NULL DEFAULT NULL COMMENT '湿度',
  `devwarning` int(255) NULL DEFAULT NULL COMMENT '告警标志',
  `devtime` datetime NULL DEFAULT NULL COMMENT '设备上送时间',
  `cursystime` datetime NULL DEFAULT NULL COMMENT '后台记录时间',
  `lowdianyawarningint` int(1) NULL DEFAULT NULL COMMENT 'bit7  低电压告警',
  `shebeiguzhang` int(255) NULL DEFAULT NULL COMMENT 'bit6 设备故障',
  `beiyong1` int(255) NULL DEFAULT NULL COMMENT 'bit5 ',
  `duandiangaojing` int(255) NULL DEFAULT NULL COMMENT 'bit4 断电告警',
  `beiyong2` int(255) NULL DEFAULT NULL COMMENT 'bit3',
  `beiyong3` int(255) NULL DEFAULT NULL COMMENT 'bit2',
  `shidugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit1',
  `wendugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit0',
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `devID`(`devID`, `devtime`, `cursystime`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 373648 CHARACTER SET = gbk COLLATE = gbk_chinese_ci COMMENT = '设备历史数据' ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for devinfo
-- ----------------------------
DROP TABLE IF EXISTS `devinfo`;
CREATE TABLE `devinfo`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `devID` int(11) NULL DEFAULT NULL COMMENT '设备id',
  `devtemper` float(255, 0) NULL DEFAULT NULL COMMENT '温度',
  `devwater` float(255, 0) NULL DEFAULT NULL COMMENT '湿度',
  `devwarning` int(255) NULL DEFAULT NULL COMMENT '告警标志',
  `devtime` datetime NULL DEFAULT NULL COMMENT '设备上送时间',
  `cursystime` datetime NULL DEFAULT NULL COMMENT '后台记录时间',
  `lowdianyawarningint` int(1) NULL DEFAULT NULL COMMENT 'bit7  低电压告警',
  `shebeiguzhang` int(255) NULL DEFAULT NULL COMMENT 'bit6 设备故障',
  `beiyong1` int(255) NULL DEFAULT NULL COMMENT 'bit5 ',
  `duandiangaojing` int(255) NULL DEFAULT NULL COMMENT 'bit4 断电告警',
  `beiyong2` int(255) NULL DEFAULT NULL COMMENT 'bit3',
  `beiyong3` int(255) NULL DEFAULT NULL COMMENT 'bit2',
  `shidugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit1',
  `wendugaojing` int(255) NULL DEFAULT NULL COMMENT 'bit0',
  `devleibie1` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL COMMENT '设备类别1',
  `devleibie2` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL COMMENT '设备类别2',
  `devposi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL COMMENT '设备位置',
  `devbeizhu` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL COMMENT '备注信息',
  `devidt` varchar(10) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `index_devid`(`devID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3752 CHARACTER SET = gbk COLLATE = gbk_chinese_ci COMMENT = '设备基础信息，考虑也存储实时信息' ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for fkjl
-- ----------------------------
DROP TABLE IF EXISTS `fkjl`;
CREATE TABLE `fkjl`  (
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `srid` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `fkriqi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `fkje` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `czry` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `sjfk` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `fkfs` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for grade
-- ----------------------------
DROP TABLE IF EXISTS `grade`;
CREATE TABLE `grade`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `remark` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 14 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for hygl
-- ----------------------------
DROP TABLE IF EXISTS `hygl`;
CREATE TABLE `hygl`  (
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `addr` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `telhome` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `cellphone` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `mail` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `website` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `introduce` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `photo` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `money` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `birthday` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `sex` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `company` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `tel_company` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `jibie` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `jifen` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `cunjie` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `ljxiaofei` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for hyglcz
-- ----------------------------
DROP TABLE IF EXISTS `hyglcz`;
CREATE TABLE `hyglcz`  (
  `ID` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `hyid` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `hyname` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `hytel` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `czrq` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `jine` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `memo` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for hyjb
-- ----------------------------
DROP TABLE IF EXISTS `hyjb`;
CREATE TABLE `hyjb`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for hyjfxf
-- ----------------------------
DROP TABLE IF EXISTS `hyjfxf`;
CREATE TABLE `hyjfxf`  (
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `riqi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `hybh` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `xfjifen` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `beizhu` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for mrje
-- ----------------------------
DROP TABLE IF EXISTS `mrje`;
CREATE TABLE `mrje`  (
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `riqi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `jine` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for myleibie
-- ----------------------------
DROP TABLE IF EXISTS `myleibie`;
CREATE TABLE `myleibie`  (
  `cur_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `parent_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `curlevel` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `curname` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for myobject
-- ----------------------------
DROP TABLE IF EXISTS `myobject`;
CREATE TABLE `myobject`  (
  `object_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `typeone_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `typetwo_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `typethr_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `beizhu` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `riqi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `ry` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_path` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for myobjectbody
-- ----------------------------
DROP TABLE IF EXISTS `myobjectbody`;
CREATE TABLE `myobjectbody`  (
  `object_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_body` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for myziliao
-- ----------------------------
DROP TABLE IF EXISTS `myziliao`;
CREATE TABLE `myziliao`  (
  `object_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `typeone_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `typetwo_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `typethr_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_cont` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for myziliaobody
-- ----------------------------
DROP TABLE IF EXISTS `myziliaobody`;
CREATE TABLE `myziliaobody`  (
  `ID` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_body` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `object_path` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for rizhi
-- ----------------------------
DROP TABLE IF EXISTS `rizhi`;
CREATE TABLE `rizhi`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `jinru` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `likai` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `caozuo` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `bianma` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for srlb
-- ----------------------------
DROP TABLE IF EXISTS `srlb`;
CREATE TABLE `srlb`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `price` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `taoxi` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `hyprice` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `clazzId` int(11) NOT NULL,
  `username` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `sex` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `remark` varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `grade` float(100, 2) NULL DEFAULT NULL,
  `dtime` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `gradeId`(`clazzId`) USING BTREE,
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`clazzId`) REFERENCES `clazz` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 36 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for tb_user
-- ----------------------------
DROP TABLE IF EXISTS `tb_user`;
CREATE TABLE `tb_user`  (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '用户编号',
  `name` varchar(30) CHARACTER SET gbk COLLATE gbk_chinese_ci NOT NULL COMMENT '用户姓名',
  `create_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '创建时间',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 11 CHARACTER SET = gbk COLLATE = gbk_chinese_ci COMMENT = '用户信息表' ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for tx
-- ----------------------------
DROP TABLE IF EXISTS `tx`;
CREATE TABLE `tx`  (
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `leibie` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `num` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `price` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 10 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for zclb
-- ----------------------------
DROP TABLE IF EXISTS `zclb`;
CREATE TABLE `zclb`  (
  `name` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `price` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `id` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = gbk COLLATE = gbk_chinese_ci ROW_FORMAT = Compact;

-- ----------------------------
-- View structure for alldev
-- ----------------------------
DROP VIEW IF EXISTS `alldev`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `alldev` AS select `v6807`.`时间` AS `时间`,`v6807`.`温度` AS `温度`,`v6807`.`湿度` AS `湿度` from `v6807`;

-- ----------------------------
-- View structure for v6807
-- ----------------------------
DROP VIEW IF EXISTS `v6807`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `v6807` AS select `devdata`.`devID` AS `6807id`,`devdata`.`devtemper` AS `6807temper`,`devdata`.`devwater` AS `6807water`,`devdata`.`devtime` AS `dtime` from `devdata` where (`devdata`.`devID` = 6807);

-- ----------------------------
-- View structure for v6808
-- ----------------------------
DROP VIEW IF EXISTS `v6808`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `v6808` AS select `devdata`.`devID` AS `6808id`,`devdata`.`devtemper` AS `6808temper`,`devdata`.`devwater` AS `6808water`,`devdata`.`devtime` AS `dtime` from `devdata` where (`devdata`.`devID` = 6808);

-- ----------------------------
-- View structure for v6813
-- ----------------------------
DROP VIEW IF EXISTS `v6813`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `v6813` AS select `devdata`.`devID` AS `6813id`,`devdata`.`devtemper` AS `6813temper`,`devdata`.`devwater` AS `6813water`,`devdata`.`devtime` AS `dtime` from `devdata` where (`devdata`.`devID` = 6813);

-- ----------------------------
-- View structure for v6814
-- ----------------------------
DROP VIEW IF EXISTS `v6814`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `v6814` AS select `devdata`.`devID` AS `6814id`,`devdata`.`devtemper` AS `6814temper`,`devdata`.`devwater` AS `6814water`,`devdata`.`devtime` AS `dtime` from `devdata` where (`devdata`.`devID` = 6814);

-- ----------------------------
-- View structure for vdevdata
-- ----------------------------
DROP VIEW IF EXISTS `vdevdata`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `vdevdata` AS select `vdevdatat`.`id` AS `id`,`vdevdatat`.`devID` AS `devID`,`vdevdatat`.`devtemper` AS `devtemper`,`vdevdatat`.`devwater` AS `devwater`,`vdevdatat`.`devwarning` AS `devwarning`,`vdevdatat`.`devtime` AS `devtime`,`vdevdatat`.`cursystime` AS `cursystime`,`vdevdatat`.`lowdianyawarningint` AS `lowdianyawarningint`,`vdevdatat`.`shebeiguzhang` AS `shebeiguzhang`,`vdevdatat`.`beiyong1` AS `beiyong1`,`vdevdatat`.`duandiangaojing` AS `duandiangaojing`,`vdevdatat`.`beiyong2` AS `beiyong2`,`vdevdatat`.`beiyong3` AS `beiyong3`,`vdevdatat`.`shidugaojing` AS `shidugaojing`,`vdevdatat`.`wendugaojing` AS `wendugaojing`,`devinfo`.`devleibie1` AS `devleibie1`,`devinfo`.`devleibie2` AS `devleibie2`,`devinfo`.`devposi` AS `devposi` from (`vdevdatat` join `devinfo` on((`vdevdatat`.`devID` = `devinfo`.`devID`))) where ((`vdevdatat`.`devwarning` <> 64) and (`vdevdatat`.`devID` < 6819)) order by `vdevdatat`.`devtime`;

-- ----------------------------
-- View structure for vdevdatat
-- ----------------------------
DROP VIEW IF EXISTS `vdevdatat`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `vdevdatat` AS select `devdata`.`id` AS `id`,`devdata`.`devID` AS `devID`,`devdata`.`devtemper` AS `devtemper`,`devdata`.`devwater` AS `devwater`,`devdata`.`devwarning` AS `devwarning`,`devdata`.`devtime` AS `devtime`,`devdata`.`cursystime` AS `cursystime`,`devdata`.`lowdianyawarningint` AS `lowdianyawarningint`,`devdata`.`shebeiguzhang` AS `shebeiguzhang`,`devdata`.`beiyong1` AS `beiyong1`,`devdata`.`duandiangaojing` AS `duandiangaojing`,`devdata`.`beiyong2` AS `beiyong2`,`devdata`.`beiyong3` AS `beiyong3`,`devdata`.`shidugaojing` AS `shidugaojing`,`devdata`.`wendugaojing` AS `wendugaojing` from `devdata` where ((minute(`devdata`.`devtime`) > 0) and (minute(`devdata`.`devtime`) <= 10) and (`devdata`.`devtime` > '2021-01-30 18:00:00')) order by `devdata`.`devtime`;

-- ----------------------------
-- View structure for vdevdatatbak20201208
-- ----------------------------
DROP VIEW IF EXISTS `vdevdatatbak20201208`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `vdevdatatbak20201208` AS select `devdata`.`id` AS `id`,`devdata`.`devID` AS `devID`,`devdata`.`devtemper` AS `devtemper`,`devdata`.`devwater` AS `devwater`,`devdata`.`devwarning` AS `devwarning`,`devdata`.`devtime` AS `devtime`,`devdata`.`cursystime` AS `cursystime`,`devdata`.`lowdianyawarningint` AS `lowdianyawarningint`,`devdata`.`shebeiguzhang` AS `shebeiguzhang`,`devdata`.`beiyong1` AS `beiyong1`,`devdata`.`duandiangaojing` AS `duandiangaojing`,`devdata`.`beiyong2` AS `beiyong2`,`devdata`.`beiyong3` AS `beiyong3`,`devdata`.`shidugaojing` AS `shidugaojing`,`devdata`.`wendugaojing` AS `wendugaojing` from `devdata` where (minute(`devdata`.`devtime`) = 0) order by `devdata`.`devtime`;

-- ----------------------------
-- View structure for vdevinfo
-- ----------------------------
DROP VIEW IF EXISTS `vdevinfo`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `vdevinfo` AS select `devinfo`.`id` AS `ID`,`devinfo`.`devID` AS `设备编码`,`devinfo`.`devtemper` AS `温度`,`devinfo`.`devwater` AS `湿度`,`devinfo`.`devwarning` AS `存在告警`,`devinfo`.`devtime` AS `时间`,`devinfo`.`lowdianyawarningint` AS `低电压告警`,`devinfo`.`shebeiguzhang` AS `设备故障`,`devinfo`.`duandiangaojing` AS `断电告警`,`devinfo`.`shidugaojing` AS `湿度告警`,`devinfo`.`wendugaojing` AS `温度告警`,`devinfo`.`devleibie1` AS `电压等级`,`devinfo`.`devleibie2` AS `设备类别`,`devinfo`.`devposi` AS `设备位置` from `devinfo`;

-- ----------------------------
-- View structure for 故障记录
-- ----------------------------
DROP VIEW IF EXISTS `故障记录`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `故障记录` AS select `devdata`.`devID` AS `设备编码`,`devdata`.`devwarning` AS `设备故障`,`devdata`.`devtime` AS `发生时间` from `devdata` where ((`devdata`.`devwarning` = 64) and (`devdata`.`devtime` between '2021-01-30 18:00:00' and '2021-09-31 23:59:59')) order by `devdata`.`devtime`;

-- ----------------------------
-- View structure for 故障记录统计
-- ----------------------------
DROP VIEW IF EXISTS `故障记录统计`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `故障记录统计` AS select `故障记录`.`设备编码` AS `设备编码`,count(0) AS `故障个数统计` from `故障记录` group by `故障记录`.`设备编码`;

-- ----------------------------
-- View structure for 故障记录统计位置
-- ----------------------------
DROP VIEW IF EXISTS `故障记录统计位置`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `故障记录统计位置` AS select `故障记录统计`.`设备编码` AS `设备编码`,`故障记录统计`.`故障个数统计` AS `故障个数统计`,`devinfo`.`devposi` AS `安装位置` from (`故障记录统计` join `devinfo` on((`故障记录统计`.`设备编码` = `devinfo`.`devID`)));

-- ----------------------------
-- View structure for 故障记录统计位置排序
-- ----------------------------
DROP VIEW IF EXISTS `故障记录统计位置排序`;
CREATE ALGORITHM = UNDEFINED DEFINER = `shouzhenwuxian`@`%` SQL SECURITY DEFINER VIEW `故障记录统计位置排序` AS select `故障记录统计位置`.`设备编码` AS `设备编码`,`故障记录统计位置`.`故障个数统计` AS `故障个数统计`,`故障记录统计位置`.`安装位置` AS `安装位置` from `故障记录统计位置` order by `故障记录统计位置`.`故障个数统计`;

-- ----------------------------
-- Event structure for event_modifydevinfo
-- ----------------------------
DROP EVENT IF EXISTS `event_modifydevinfo`;
delimiter ;;
CREATE DEFINER = `shouzhenwuxian`@`%` EVENT `event_modifydevinfo`
ON SCHEDULE
EVERY '3' SECOND STARTS '2021-01-18 10:57:28'
ON COMPLETION PRESERVE
COMMENT '修正数据任务'
DO update devinfo set devtemper = 2,devwater=30,devwarning=0,shebeiguzhang=0 where devwarning =64 and devID < 6819
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
