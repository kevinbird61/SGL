AM_CFLAGS = \
	-I$(top_srcdir)/include/GL \
	-I$(top_srcdir)/src/sgl \
	-Wall -O2 -g
lib_LTLIBRARIES = libSGLUT.la
libSGLUT_la_LDFLAGS = \
		-lX11 \
		-version-info $(LIBSGL_CURRENT):$(LIBSGL_REVISION):$(LIBSGL_AGE)
libSGLUT_la_SOURCES = \
		sglutapi.h \
		types.h \
		context.c context.h \
		geometry.c geometry.h \
		teapot.c teapot_data.h
