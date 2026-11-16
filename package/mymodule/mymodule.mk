MYMODULE_VERSION = 1.0
MYMODULE_SITE = $(HOME)/module_lab/buildroot-mymodule
MYMODULE_SITE_METHOD = local

$(eval $(kernel-module))
$(eval $(generic-package))
