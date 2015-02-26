call:RefreshCMakeLists

goto:eof

:RefreshCMakeLists
	for /d /r %%A in (*) do (
		del %%A\CMakeLists.txt
		copy %CD%\CMakeLists.txt %%A\CMakeLists.txt
		)
goto:eof